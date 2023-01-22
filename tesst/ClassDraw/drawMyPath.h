#ifndef DRAWMYPATH_H
#define DRAWMYPATH_H

#include <QObject>
#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QBrush>
#include <QPainterPath>
#include <QPointF>

class drawMyPath:public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QList<QVariant> path READ path WRITE setpath NOTIFY pathChanged)
    QML_ELEMENT
public:
    drawMyPath(QQuickItem *parent = nullptr);
    void paint(QPainter *painter);

    const QColor &color() const;
    void setColor(const QColor &newColor);

    const QList<QVariant> &path() const;
    void setpath(const QList<QVariant> &newpath);

signals:
    void colorChanged();
    void pathChanged();

private:
    QPainterPath my_path;
    QColor m_color = "red";
    QList<QVariant> m_path;
    QList<QPointF> PointTemp;
    QPointF Point;
};

#endif // DRAWMYPATH_H
