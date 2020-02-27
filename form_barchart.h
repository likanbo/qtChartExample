#ifndef FORM_BARCHART_H
#define FORM_BARCHART_H

#include <QWidget>

namespace Ui {
class Form_BarChart;
}

class Form_BarChart : public QWidget
{
    Q_OBJECT

public:
    explicit Form_BarChart(QWidget *parent = nullptr);
    ~Form_BarChart();

private:
    Ui::Form_BarChart *ui;
};

#endif // FORM_BARCHART_H
