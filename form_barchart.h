#ifndef FORM_BARCHART_H
#define FORM_BARCHART_H

#include <QWidget>
#include <QChart>
#include <QStackedBarSeries>
#include "constdefine.h"
#include <QBarSet>
#include <QValueAxis>
#include <QChartView>

namespace Ui {
class Form_BarChart;
}

QT_CHARTS_USE_NAMESPACE

class Form_BarChart : public QWidget
{
    Q_OBJECT

public:
    explicit Form_BarChart(QWidget *parent = nullptr);
    ~Form_BarChart();

private:
    Ui::Form_BarChart *ui;
    DataTable m_dataTable;
    int m_valueMax;
    int m_valueCount;
    int m_listCount;

    QChart *createBarChart(int valueCount) const;
};

#endif // FORM_BARCHART_H
