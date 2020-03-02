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

    Form_BarChart *barChart = new Form_BarChart();
    layOut->addWidget(barChart,0,1);

    Form_PieChart *pieChart = new Form_PieChart();
    layOut->addWidget(pieChart,0,2);

    ui->centralwidget->setLayout(layOut);

}

MainWindow::~MainWindow()
{
    delete ui;
}

