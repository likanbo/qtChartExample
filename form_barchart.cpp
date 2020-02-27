#include "form_barchart.h"
#include "ui_form_barchart.h"

Form_BarChart::Form_BarChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_BarChart)
{
    ui->setupUi(this);

    //ui->pushButton->setText()

}

Form_BarChart::~Form_BarChart()
{
    delete ui;
}
