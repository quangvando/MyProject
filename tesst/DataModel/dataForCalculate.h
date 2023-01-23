#ifndef DATAFORCALCULATE_H
#define DATAFORCALCULATE_H

#include <QObject>
#include <QPointF>

class dataForCalculate : public QObject
{
    Q_OBJECT
public:
    dataForCalculate();

    void getCases();
    Q_INVOKABLE void getPointOder();
    void getDis(QVector<QPointF> pointOder, QVector<QVector<int>> caseList);
    bool checkIntersect(QPointF A, QPointF B, QPointF C, QPointF D);
    float distance(QPointF A, QPointF B);

    Q_INVOKABLE void getPoint(float x,float y);
    Q_INVOKABLE void getPoints();
    bool checkIn(QPointF A, QPointF B, QVector<QPointF> C);
    Q_INVOKABLE void checkFist();

private:
    QVector<QPointF> pointOder;
    QVector<QVector<int>> tempList;
    QVector<int> tempList1;

    QVector<QVector<int>> caseList;
    QVector<int> caseList1;

    QVector<QVector<float>> disList;

    QVector<QVector<QPointF>> P;
    QVector<QPointF> pTemp;
    QPointF P1;
//    QPointF A = QPointF(1.0, 3.0);
//    QPointF B = QPointF(3.0, 5.0);
//    QPointF C = QPointF(5.0, 3.0);
//    QPointF D = QPointF(3.0, 3.1);


};

#endif // DATAFORCALCULATE_H
