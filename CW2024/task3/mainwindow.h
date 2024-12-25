#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget * parent = nullptr);
    ~MainWindow();

private slots:
    void onTabulate();

private:
    QLineEdit * startEdit;
    QLineEdit * endEdit;
    QLineEdit * stepEdit;
    QPushButton * tabulateButton;
    QListWidget * xText;
    QListWidget * yText;
    QtCharts::QLineSeries * series;
    QtCharts::QChartView * chartView;
};

#endif // MAINWINDOW_H
