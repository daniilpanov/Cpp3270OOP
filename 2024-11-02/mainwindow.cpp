#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::solveKramer()
{
    ui->solveResult->clear();
    InputParser parser;
    if (!parser.parseString(ui->systemKramerInput->toPlainText()))
    {
        ui->solveResult->addItem(QString("Invalid data!"));
        return;
    }
    KramerSystem kramer(parser.wsize, parser.kMatrix, parser.bMatrix);
    try
    {
        double* result = kramer.solve();
        for (int i{0}; i < parser.wsize; ++i)
            ui->solveResult->addItem(QString::number(result[i]));
        delete[] result;
    }
    catch (bool)
    {
        ui->solveResult->addItem(QString("System has an infinite number of solutions!"));
    }
}

