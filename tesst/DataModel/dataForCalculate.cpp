
#include "dataForCalculate.h"
#include <QDebug>

dataForCalculate::dataForCalculate()
{
    //qDebug()<< "ok";
    //    pTemp.push_back(A);
    //    pTemp.push_back(B);
    //    pTemp.push_back(C);
    //    pTemp.push_back(D);
}

void dataForCalculate::getPointOder()
{
    for (int i = 0; i < P.length(); i++)
    {
        for (int j = 0; j < P[i].length(); j++)
        {
            tempList1.push_back(0);
        }
        tempList.push_back(tempList1);
    }

    for (int i = 0; i < P.length(); i++)
    {
        for (int j = 0; j < P[i].length(); j++)
        {
            pointOder.append(P[i][j]);
            tempList[i][j] = pointOder.length() - 1;
            //qDebug()<< tempList[i][j];
            //qDebug()<< pointOder[tempList[i][j]];
        }
    }
}

void dataForCalculate::getCases()
{
    for(int i = 0; i < P.length(); i++)
    {
        for(int j = 0; j < P[i].length(); j++)
        {
            for(int e = 0; e < P.length(); e++)
            {
                for(int k = 0; k < P[e].length(); k++)
                {
                    bool test = true;
                    for(int m = 0; m < P.length(); m++)
                    {
                        for(int n = 0; n < P[m].length(); n++)//kiểm tra đoạn thẳng trên hình có giao với các cạnh của nó ko
                        {
                            if (i == e)
                            {
                                if (j == k) continue;
                                if((j != (k+1) && j != k-1)&&(j != (k-1) && j != k-P[e].length()+1)&&(j != (k+1) && j != P[e].length()+k-1))//điều kiện ko nhận hai điểm trước và sau
                                {
                                    //qDebug()<<"ok1";
                                    if(checkIntersect(P[i][j], P[e][k], P[m][n], P[m][ ((n+1) == P[m].length()) ? 0:(n+1)]))
                                    {
                                        test = false;
                                        goto jump;
                                    }
                                }
                            }
                            if (i != e)
                            {
                                //qDebug()<<"ok";
                                if(checkIntersect(P[i][j], P[e][k], P[m][n], P[m][ ((n+1) == P[m].length()) ? 0:(n+1)]))
                                {
                                    test = false;
                                    goto jump;
                                }
                            }
                        }
                    }
jump:
                    if((i==e) && (j!=k) && ((j != (k+1) && j != k-1)&&(j != (k-1) && j != k-P[e].length()+1)&&(j != (k+1) && j != P[e].length()+k-1)))
                    {
                        if(!checkIn(P[i][j], P[e][k], P[i]))
                        {
                            //qDebug()<<"ok";
                            caseList1.push_back(tempList[e][k]);

                        }
                    }
                    if(i != e && test)
                    {
                        //qDebug()<<"ok";
                        caseList1.push_back(tempList[e][k]);
                    }
                }
            }
            caseList1.push_back(tempList[i][((j+1) == P[i].length()) ? 0:(j+1)]);
            caseList1.push_back(tempList[i][0 == j ? (P[i].length()-1):(j-1)]);
            caseList.push_back(caseList1);
            caseList1.clear();
        }
    }
}

bool dataForCalculate::checkIntersect(QPointF A, QPointF B, QPointF C, QPointF D)
{
    qDebug()<<"check intersect";
    float E = (D.y() - C.y()) / (D.x() - C.x());
    float F = (B.y() - A.y()) / (B.x() - A.x());
    float X = (E*C.x() - F*A.x() - C.y() + A.y())/(E-F);
    if((A.x() +2  <= X) && (X <= B.x()-2) && (C.x() +2  <= X) && (X <= D.x()-2)) return true;
    else if((A.x() +2  <= X) && (X <= B.x()-2) && (D.x() +2  <= X) && (X <= C.x()-2)) return true;
    else if((B.x()+2 <= X) && (X <= A.x()-2)&& (C.x() +2  <= X) && (X <= D.x()-2)) return true;
    else if((B.x()+2 <= X) && (X <= A.x()-2)&& (D.x() +2  <= X) && (X <= C.x()-2)) return true;
    else return false;
}

void dataForCalculate::getPoint(float x,float y)
{
    P1.setX(x);
    P1.setY(y);
    pTemp.push_back(P1);
    //qDebug()<< "ok1";
}

void dataForCalculate::getPoints()
{
    P.push_back(pTemp);
    pTemp.clear();
    //qDebug()<< "ok2";
}
bool dataForCalculate::checkIn(QPointF A, QPointF B, QVector<QPointF> C)
{
    float xA = (A.x()+B.x())/2;
    float yA = (A.y()+B.y())/2;
    float xB = xA + 5;
    float yB = yA + 5;
    float F = (yB - yA) / (xB - xA);
    int count = 0;
    for(int i = 0; i < C.length(); i++)
    {
        float E = (C[(i+1) == (C.length()) ? 0:(i+1)].y() - C[i].y()) / (C[(i+1) == (C.length()) ? 0:(i+1)].x() - C[i].x());
        float X = (E*C[i].x() - F*xA - C[i].y() + yA)/(E-F);
        if((X > xA) && (((C[i].x() < X)&&(X < C[(i+1) == (C.length()) ? 0:(i+1)].x())) || (((C[(i+1) == (C.length()) ? 0:(i+1)].x()) < X)&&(X < C[i].x()))))
        {
            count ++;
            //qDebug()<<count;
        }

    }
    if ((count % 2)==1)
    {
        //qDebug()<<"true";
        return true;
    }
    else
    {
        //qDebug()<<"false";
        return false;
    }
}

void dataForCalculate::checkFist()
{
    getCases();
    qDebug()<< caseList.length();
    for(int i = 0; i< caseList.length();i++)
    {
        qDebug()<< caseList[i];
    }

}

























