#ifndef MYPOINTDATAMODEL_H
#define MYPOINTDATAMODEL_H

#include <QObject>
#include <QAbstractListModel>

//---------------------class myBaseDataItem ---------------------------
class myPointItem{
public:
    explicit myPointItem(const float &x, const float &y);
    float getX() const;
    float getY() const;
    //bool setX(const float &x);
    //bool setY(const float &y);
private:
    float x;
    float y;
};

//---------------------class myBaseDataItem ---------------------------
class myPointDataModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit myPointDataModel(QObject *parent = nullptr);
    enum modelRole
    {
        xRole = Qt::UserRole +1,
        yRole
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    //bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Q_INVOKABLE void addItem(float x, float y);

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<myPointItem> m_data;
};
#endif // MYPOINTDATAMODEL_H
