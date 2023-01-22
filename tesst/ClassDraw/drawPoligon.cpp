#include "drawPoligon.h"
#include <QDebug>

drawPoligon::drawPoligon(QQuickItem *parent):QQuickPaintedItem(parent)
{

}

void drawPoligon::paint(QPainter *painter)
{
    for(int i = 0; i < P.length(); i++) {
        QVariant v = P[i];
        Q = v.toPointF();
        P1.push_back(Q);
    }
    painter->setPen(QPen(m_color));
    painter->setBrush(QColor("blue"));
    m_path.addPolygon(P1);
    m_path.closeSubpath();
    painter->drawPath(m_path);
    P.clear();
}

const QColor &drawPoligon::color() const
{
    return m_color;
}
void drawPoligon::setColor(const QColor &newColor)
{
    if (m_color == newColor)
        return;
    m_color = newColor;
    emit colorChanged();
    //update();

}
const QList<QVariant> &drawPoligon::poli() const
{
    return P;
}

void drawPoligon::setpoli(const QList<QVariant> &newpoli)
{
    P = newpoli;
    emit poliChanged();
    //update();
}
