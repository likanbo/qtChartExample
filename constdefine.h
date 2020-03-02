#ifndef CONSTDEFINE_H
#define CONSTDEFINE_H
#include <QPointF>
#include <QList>
#include <QMap>
#include <QRandomGenerator>

typedef QPair<QPointF, QString> Data;
typedef QList<Data> DataList;
typedef QMap<QString,DataList> DataTable;

static DataTable generateRandomData(int listCount, int valueMax, int valueCount)
{
    DataTable dataTable;

    // generate random data
    for (int i(0); i < listCount; i++) {
        DataList dataList;
        qreal yValue(0);
        for (int j(0); j < valueCount; j++) {
            yValue = yValue + QRandomGenerator::global()->bounded(valueMax / (qreal) valueCount);
            QPointF value((j + QRandomGenerator::global()->generateDouble()) * ((qreal) valueMax / (qreal) valueCount),
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

#endif // CONSTDEFINE_H
