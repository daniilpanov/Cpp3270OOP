#include <QCoreApplication>
#include <QTcpSocket>
#include <QFile>
#include <QDebug>

class SimpleTcpClient {
public:
    SimpleTcpClient(const QString &host, quint16 port) {
        socket.connectToHost(host, port);
        if (socket.waitForConnected(1000)) {
            onConnected();
        } else {
            qDebug() << "Connection failed:" << socket.errorString();
            QCoreApplication::quit();
        }
    }

    void onConnected() {
        qDebug() << "Connected to server!";
        QFile file("send_file.txt");
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "Failed to open file!";
            socket.disconnectFromHost();
            QCoreApplication::quit();
            return;
        }

        QByteArray buffer = file.readAll();
        file.close();

        socket.write(buffer);
        socket.flush();
        qDebug() << "Data sent.";

        if (socket.waitForBytesWritten(3000)) {
            socket.disconnectFromHost();
            if (socket.waitForDisconnected(3000)) {
                qDebug() << "Disconnected from server.";
            } else {
                qDebug() << "Failed to disconnect:" << socket.errorString();
            }
        } else {
            qDebug() << "Failed to write data:" << socket.errorString();
        }

        QCoreApplication::quit();
    }

private:
    QTcpSocket socket;
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    SimpleTcpClient client("127.0.0.1", 12345);

    return a.exec();
}
