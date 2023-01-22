#ifndef MYBASEDATAMODEL_H
#define MYBASEDATAMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QPointF>
#include <QDebug>

//---------------------class myBaseDataItem ---------------------------
class myBaseDataItem
{
public:
    explicit myBaseDataItem(const QList<QVariant> &Points);
    QVector<QVariant> getPoints() const;
    //bool setPoints(const QList<QVariant> &Points);
    QVariant operator[](int index)
    {
        return Points[index];
    }

    int getLength()
    {
        return Points.length();
    }
private:
    QList<QVariant> Points;
};

//---------------------class myBaseDataModel ---------------------------
class myBaseDataModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit myBaseDataModel(QObject *parent = nullptr);
//    myBaseDataModel( myBaseDataModel& other)//:QAbstractListModel(other)
//    {
//        for(int i = 0; i < m_data.length(); i++)
//        {
//            for(int j = 0; j < m_data[i].getLength(); j++)
//            {
//                this->m_data[i][j] = other.m_data[i][j];
//            }
//        }
//    }
    myBaseDataModel(QList<QList<QVariant>> Q);
    enum modelRole{
        pointsRole = Qt::UserRole +1
    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    //bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Q_INVOKABLE void addItem();
    Q_INVOKABLE void getPoint(float x, float y);

    myBaseDataItem operator[](int index)
    {
        return m_data[index];
    }
    int getLength()
    {
        return m_data.length();
    }


protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    QList<myBaseDataItem> m_data;
    QList<QVariant> Ptemp;
    QPointF P;
};

#endif // MYBASEDATAMODEL_H
