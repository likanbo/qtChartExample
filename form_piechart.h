#ifndef FORM_PIECHART_H
#define FORM_PIECHART_H

#include <QWidget>
#include "constdefine.h"
#include <QChart>
#include <QPieSeries>
#include <QPieSlice>
#include <QChartView>

namespace Ui {
class Form_PieChart;
}
QT_CHARTS_USE_NAMESPACE

class Form_PieChart : public QWidget
{
    Q_OBJECT

public:
    explicit Form_PieChart(QWidget *parent = nullptr);
    ~Form_PieChart();

private:
    Ui::Form_PieChart *ui;

    QChart *createPieChart() const;

    int m_listCount;
    int m_valueMax;
    int m_valueCount;
    DataTable m_dataTable;

};

#endif // FORM_PIECHART_H
