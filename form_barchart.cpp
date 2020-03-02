#include "form_barchart.h"
#include "ui_form_barchart.h"

Form_BarChart::Form_BarChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_BarChart)
{
    ui->setupUi(this);

    m_listCount = 3;
    m_valueMax = 10;
    m_valueCount = 7;
    m_dataTable = ::generateRandomData(m_listCount, m_valueMax, m_valueCount);


     QChartView *chartView;

     chartView = new QChartView(createBarChart(m_valueCount));
     ui->gridLayout->addWidget(chartView, 0, 0);

}

Form_BarChart::~Form_BarChart()
{
    delete ui;
}

QChart *Form_BarChart::createBarChart(int valueCount) const
{
    Q_UNUSED(valueCount);
    QChart *chart = new QChart();
    chart->setTitle("Bar chart");

    QStackedBarSeries *series = new QStackedBarSeries(chart);


    for (DataTable::const_iterator iter = m_dataTable.constBegin();iter != m_dataTable.constEnd();iter++) {
        QBarSet *set = new QBarSet("Bar set " + iter.key());
        for (const Data &data : iter.value())
            *set << data.first.y();
        series->append(set);
    }
    chart->addSeries(series);

    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, m_valueMax * 2);
    // Add space to label to add space between labels and axis
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%.1f  ");

    return chart;
}
