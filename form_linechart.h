#ifndef FORM_LINECHART_H
#define FORM_LINECHART_H

#include <QWidget>
#include <QChart>
#include <QLineSeries>
#include <QValueAxis>
#include <QRandomGenerator>
#include <QChartView>
#include "constdefine.h"

namespace Ui {
class Form_LineChart;
}

QT_CHARTS_USE_NAMESPACE

class Form_LineChart : public QWidget
{
    Q_OBJECT

public:
    explicit Form_LineChart(QWidget *parent = nullptr);
    explicit Form_LineChart(DataTable dt,QWidget *parent = nullptr);
    ~Form_LineChart();


private:

    QChart *createLineChart() const;
    DataTable generateRandomData(int listCount, int valueMax, int valueCount) const;


    int m_listCount;
    int m_valueMax;
    int m_valueCount;
    DataTable m_dataTable;


    Ui::Form_LineChart *ui;
};

#endif // FORM_LINECHART_H
