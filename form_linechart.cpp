#include "form_linechart.h"
#include "ui_form_linechart.h"

Form_LineChart::Form_LineChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form_LineChart)
{
    ui->setupUi(this);

    m_listCount = 3;
    m_valueMax = 10;
    m_valueCount = 7;
    m_dataTable = generateRandomData(m_listCount, m_valueMax, m_valueCount);

    QChartView *chartView = nullptr;

    //![5]
    chartView = new QChartView(createLineChart());
    ui->gridLayout->addWidget(chartView, 0, 0);
    //![5]
    //!
}

Form_LineChart::Form_LineChart(DataTable dt, QWidget *parent)
{

    m_listCount = dt.count();
    m_valueMax = 10;
    m_valueCount = dt.first().count();
    m_dataTable = dt;//generateRandomData(m_listCount, m_valueMax, m_valueCount);

    QChartView *chartView = nullptr;

    //![5]
    chartView = new QChartView(createLineChart());
    ui->gridLayout->addWidget(chartView, 0, 0);
    //![5]
    //!
    //!
}

Form_LineChart::~Form_LineChart()
{
    delete ui;
}

DataTable Form_LineChart::generateRandomData(int listCount, int valueMax, int valueCount) const
{
    DataTable dataTable;

    // generate random data
    for (int i(0); i < listCount; i++) {
        DataList dataList;
        qreal yValue(0);
        for (int j(0); j < valueCount; j++) {
            yValue = yValue + QRandomGenerator::global()->bounded(valueMax / (qreal) valueCount);
            QPointF value((j + QRandomGenerator::global()->generateDouble()) * ((qreal) m_valueMax / (qreal) valueCount),
                          yValue);
            QString label = "Slice " + QString::number(i) + ":" + QString::number(j);
            dataList << Data(value, label);
        }
        QString lineTitle = "Line"+QString::number(i);

        if(dataTable.contains(lineTitle))
        {
            dataTable[lineTitle] = dataList;
        }
        else
        {
            dataTable.insert(lineTitle,dataList);
        }
    }

    return dataTable;
}

QChart *Form_LineChart::createLineChart() const
{
    //![1]
    QChart *chart = new QChart();
    chart->setTitle("Line chart");
    //![1]

    //![2]
    QString name("Series ");
    int nameIndex = 0;


    for (DataTable::const_iterator iter = m_dataTable.constBegin();iter != m_dataTable.constEnd();iter++) {
        QLineSeries *series = new QLineSeries(chart);
        for (const Data &data : iter.value())
            series->append(data.first);
        series->setName(iter.key());
        nameIndex++;
        chart->addSeries(series);
    }
    //![2]

    //![3]
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0, m_valueMax);
    chart->axes(Qt::Vertical).first()->setRange(0, m_valueCount);
    //![3]
    //![4]
    // Add space to label to add space between labels and axis
    QValueAxis *axisY = qobject_cast<QValueAxis*>(chart->axes(Qt::Vertical).first());
    Q_ASSERT(axisY);
    axisY->setLabelFormat("%.1f  ");
    //![4]

    return chart;
}
