#ifndef drawPoligon_H
#define drawPoligon_H

#include <QObject>
#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QBrush>
#include <QPainterPath>
#include <QPointF>

class drawPoligon:public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QList<QVariant> poli READ poli WRITE setpoli NOTIFY poliChanged)
    QML_ELEMENT
public:
    drawPoligon(QQuickItem *parent = nullptr);
    void paint(QPainter *painter);
    const QColor &color() const;
    const QList<QVariant> &poli() const;
    void setColor(const QColor &newColor);
    void setpoli(const QList<QVariant> &newpoli);

signals:
    void colorChanged();
    void poliChanged();

private:
    QPainterPath m_path;
    QColor m_color;
    QList<QVariant> P;
    QList<QPointF> P1;
    QPointF Q;
};

#endif // drawPoligon_H
