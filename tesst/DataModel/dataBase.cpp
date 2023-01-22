#include "dataBase.h"
#include <QDebug>
dataBase::dataBase()
{

}

void dataBase::getPoint(float x,float y)
{
    P1.setX(x);
    P1.setY(y);
    pTemp.push_back(P1);
}

void dataBase::getPoints()
{
    P.push_back(pTemp);
    pTemp.clear();
}

