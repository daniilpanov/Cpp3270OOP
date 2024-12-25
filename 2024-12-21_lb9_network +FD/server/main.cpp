#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>

class SimpleTcpServer : public QTcpServer {
public:
    SimpleTcpServer(QObject *parent = nullptr) : QTcpServer(parent) {
        connect(this, &QTcpServer::newConnection, this, &SimpleTcpServer::onNewConnection);
    }

private slots:
    void onNewConnection() {
        QTcpSocket *clientSocket = nextPendingConnection();
        connect(clientSocket, &QTcpSocket::readyRead, [clientSocket]() {
            QByteArray data = clientSocket->readAll();
            qDebug() << "Received data:" << data;

            QFile receivedFile("received_file.txt");
            if (receivedFile.open(QIODevice::WriteOnly)) {
                receivedFile.write(data);
                receivedFile.close();
                qDebug() << "Data saved to received_file.txt";
            } else {
                qDebug() << "Failed to save file!";
            }

            clientSocket->write("Data received");
            clientSocket->flush();
            clientSocket->disconnectFromHost();
        });

        connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
        qDebug() << "Client connected!";
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    SimpleTcpServer server;
    if (!server.listen(QHostAddress::Any, 12345)) {
        qDebug() << "Server could not start!";
        return 1;
    }

    qDebug() << "Server started on port" << server.serverPort();

    return a.exec();
}
