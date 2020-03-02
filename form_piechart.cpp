#include "form_piechart.h"
#include "ui_form_piechart.h"

Form_PieChart::Form_PieChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_PieChart)
{
    ui->setupUi(this);

    m_listCount = 3;
    m_valueMax = 10;
    m_valueCount = 7;
    m_dataTable = ::generateRandomData(m_listCount, m_valueMax, m_valueCount);


    //create charts

    QChartView *chartView;


    chartView = new QChartView(createPieChart());
    // Funny things happen if the pie slice labels do not fit the screen, so we ignore size policy
    chartView->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    ui->gridLayout->addWidget(chartView, 0, 0);

}

Form_PieChart::~Form_PieChart()
{
    delete ui;
}

QChart *Form_PieChart::createPieChart() const
{
    QChart *chart = new QChart();
    chart->setTitle("Pie chart");

    QPieSeries *series = new QPieSeries(chart);
    for (const Data &data : m_dataTable[0]) {
        QPieSlice *slice = series->append(data.second, data.first.y());
        if (data == m_dataTable[0].first()) {
            // Show the first slice exploded with label
            slice->setLabelVisible();
            slice->setExploded();
            slice->setExplodeDistanceFactor(0.5);
        }
    }
    series->setPieSize(0.4);
    chart->addSeries(series);

    return chart;
}
