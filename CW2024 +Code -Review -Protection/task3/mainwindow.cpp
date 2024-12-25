#include <cmath>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollBar>
#include <QDoubleValidator>
#include <QMessageBox>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include "mainwindow.h"
#include "config.h"
#include "tabulator.h"
#include "currentfunction.h"

double locateNumber(std::string &);

MainWindow::MainWindow(QWidget * parent)
    : QMainWindow(parent) {
    QWidget::showMaximized();
    setWindowTitle("Function tabulating: y(x) = sin(x) * cos(x) * e^x");

    QWidget * centralWidget {new QWidget(this)};
    setCentralWidget(centralWidget);

    QHBoxLayout * mainLayout {new QHBoxLayout(centralWidget)};

    QVBoxLayout * dataLayout {new QVBoxLayout()};
    mainLayout->addLayout(dataLayout);

    QHBoxLayout * inputLayout {new QHBoxLayout()};
    dataLayout->addLayout(inputLayout);

    QLabel * startLabel {new QLabel("Start X value:")};
    inputLayout->addWidget(startLabel);

    startEdit = new QLineEdit();
    startEdit->setValidator(new QDoubleValidator());
    startEdit->setText("-10");
    inputLayout->addWidget(startEdit);

    QLabel * endLabel {new QLabel("End X value:")};
    inputLayout->addWidget(endLabel);

    endEdit = new QLineEdit();
    endEdit->setValidator(new QDoubleValidator());
    endEdit->setText("10");
    inputLayout->addWidget(endEdit);

    QLabel * stepLabel {new QLabel("Step:")};
    inputLayout->addWidget(stepLabel);

    stepEdit = new QLineEdit();
    stepEdit->setValidator(new QDoubleValidator());
    stepEdit->setText("0,01");
    inputLayout->addWidget(stepEdit);

    tabulateButton = new QPushButton("Tabulate");
    inputLayout->addWidget(tabulateButton);

    connect(tabulateButton, &QPushButton::clicked, this, &MainWindow::onTabulate);

    QHBoxLayout * outputLayout {new QHBoxLayout()};
    dataLayout->addLayout(outputLayout);

    xText = new QListWidget();
    outputLayout->addWidget(xText);

    yText = new QListWidget();
    outputLayout->addWidget(yText);

    connect(xText->verticalScrollBar(), &QScrollBar::valueChanged,
            yText->verticalScrollBar(), &QScrollBar::setValue);
    connect(yText->verticalScrollBar(), &QScrollBar::valueChanged,
            xText->verticalScrollBar(), &QScrollBar::setValue);

    chartView = new QtCharts::QChartView(this);
    mainLayout->addWidget(chartView);
}

MainWindow::~MainWindow() {}

void MainWindow::onTabulate() {
    xText->clear();
    yText->clear();

    bool ok;
    TabulateConfig conf;
    conf.start = startEdit->text().replace(',', '.').toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Error", "Incorrect start X value");
        return;
    }

    conf.end = endEdit->text().replace(',', '.').toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Error", "Incorrect end X value");
        return;
    }

    conf.step = stepEdit->text().replace(',', '.').toDouble(&ok);
    if (!ok || conf.step <= 0) {
        QMessageBox::warning(this, "Error", "Incorrect step value");
        return;
    }

    Tabulator tabulator(conf);
    const CurrentFunction * func {new CurrentFunction()};
    tabulator.addFunctionObject(func);
    double * outX = new double[tabulator.length];
    double * outY = new double[tabulator.length];
    tabulator.tabulate(outX, outY);

    // Update charts
    QtCharts::QLineSeries * series {new QtCharts::QLineSeries()};
    QtCharts::QChart * chart {new QtCharts::QChart()};
    chart->legend()->hide();
    QPen pen(QColor(0, 0, 255));
    pen.setWidth(2);
    series->setPen(pen);

    double x, y;
    double minX {outX[0]};
    double maxX {outX[0]};
    double minY {outY[0]};
    double maxY {outY[0]};
    for (int i{0}; i < tabulator.length; ++i)
    {
        x = outX[i];

        if (x < minX) minX = x;
        if (x > maxX) maxX = x;

        QString valX {QString::number(x)};
        xText->addItem(valX);

        y = outY[i];
        if (std::isnan(y))
        {
            QString valY("Undefined");
            yText->addItem(valY);
            chart->addSeries(series);
            series = new QtCharts::QLineSeries();
            series->setPen(pen);
        }
        else
        {
            QString valY{QString::number(y)};
            yText->addItem(valY);
            if (y < minY) minY = y;
            if (y > maxY) maxY = y;
            series->append(x, y);
        }
    }
    chart->addSeries(series);

    chart->createDefaultAxes();

    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    delete[] outX;
    delete[] outY;
}
