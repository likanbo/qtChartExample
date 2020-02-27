#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QGridLayout *layOut = new QGridLayout(this);


    Form_LineChart *lineChart = new Form_LineChart();
    layOut->addWidget(lineChart,0,0);

    ui->centralwidget->setLayout(layOut);

}

MainWindow::~MainWindow()
{
    delete ui;
}

