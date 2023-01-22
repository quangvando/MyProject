#include "drawMyPath.h"
#include <QDebug>

drawMyPath::drawMyPath(QQuickItem *parent) : QQuickPaintedItem(parent)
{
}

void drawMyPath::paint(QPainter *painter)
{
    for (int i = 0; i < m_path.length(); i++)
    {
        QVariant v = m_path[i];
        Point = v.toPointF();
        PointTemp.push_back(Point);
    }
    painter->setPen(QPen(m_color));
    my_path.addPolygon(PointTemp);
    painter->drawPath(my_path);
    PointTemp.clear();
}

const QColor &drawMyPath::color() const
{
    return m_color;
}

void drawMyPath::setColor(const QColor &newColor)
{
    if (m_color == newColor)
        return;
    m_color = newColor;
    emit colorChanged();
    //update();
}

const QList<QVariant> &drawMyPath::path() const
{
    return m_path;
}

void drawMyPath::setpath(const QList<QVariant> &newpath)
{
    m_path = newpath;
    emit pathChanged();
}
