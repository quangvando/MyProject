#ifndef DRAWLINE_H
#define DRAWLINE_H

#include <QObject>
#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QBrush>
#include <QPainterPath>
#include <QPointF>

class drawLine:public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QList<QVariant> line READ line WRITE setline NOTIFY lineChanged)
    QML_ELEMENT
public:
    drawLine(QQuickItem *parent = nullptr);
    void paint(QPainter *painter);

    const QColor &color() const;
    void setColor(const QColor &newColor);

    const QList<QVariant> &line() const;
    void setline(const QList<QVariant> &newline);

signals:
    void colorChanged();
    void lineChanged();

private:
    QColor m_color = "red";
    QList<QVariant> m_line;
    QList<QPointF> PointTemp;
    QPointF Point;
};

#endif // DRAWLINE_H
