#include "drawLine.h"
#include <QDebug>

drawLine::drawLine(QQuickItem *parent) : QQuickPaintedItem(parent)
{
}

void drawLine::paint(QPainter *painter)
{
    for (int i = 0; i < 2; i++)
    {
        QVariant v = m_line[i];
        Point = v.toPointF();
        PointTemp.push_back(Point);
    }
    painter->setPen(QPen(m_color));
    painter->drawLine(PointTemp[0], PointTemp[1]);
    PointTemp.clear();
}

const QColor &drawLine::color() const
{
    return m_color;
}

void drawLine::setColor(const QColor &newColor)
{
    if (m_color == newColor)
        return;
    m_color = newColor;
    emit colorChanged();
    //update();
}

const QList<QVariant> &drawLine::line() const
{
    return m_line;
}

void drawLine::setline(const QList<QVariant> &newline)
{
//    if (m_line == newLine)
//        return;
    m_line = newline;
    emit lineChanged();
}
