#ifndef CHECKINTER_H
#define CHECKINTER_H

#include <QObject>
#include <QPointF>

class dataBase:public QObject
{
    Q_OBJECT
public:
    dataBase();
    Q_INVOKABLE void getPoint(float x,float y);
    Q_INVOKABLE void getPoints();

    QVector<QVector<QPointF>> getValue()
    {
        return P;
    }
private:
    QVector<QVector<QPointF>> P;
    QVector<QPointF> pTemp;
    QPointF P1;
};

#endif // CHECKINTER_H
