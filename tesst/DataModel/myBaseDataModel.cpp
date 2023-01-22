#include "myBaseDataModel.h"

//---------------------class myBaseDataItem ---------------------------
myBaseDataItem::myBaseDataItem(const QList<QVariant> &Points)
{
    this->Points = Points;
};
QVector<QVariant> myBaseDataItem::getPoints() const
{
    return this->Points;
}
//bool myBaseDataItem::setPoints(const QList<QVariant> &Points)
//{
//    this->Points = Points;
//    return true;
//}

//---------------------class myBaseDataModel ---------------------------
myBaseDataModel::myBaseDataModel(QObject *parent):QAbstractListModel(parent)
{
    Q_UNUSED(parent);
}
myBaseDataModel::myBaseDataModel(QList<QList<QVariant>> Q)
{
    for (int i = 0; i < Q.length(); i++)
    {
        for(int j = 0; j < Q[i].length();j++)
        {
            m_data[i][j] = Q[i][j];
        }
    }
}

int myBaseDataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.length();
}

QVariant myBaseDataModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }
    const myBaseDataItem &item = m_data[index.row()];
    switch (role)
    {
    case pointsRole:
        return item.getPoints();
    default:
        return QVariant();
    }
}

//bool myBaseDataModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    //Q_UNUSED(parent);
//    if(!index.isValid())
//    {
//        return false;
//    }
//    myBaseDataItem &item = m_data[index.row()];
//    switch (role)
//    {
//        case pointsRole:
//            return item.setPoints(value.toList());
//        default:
//            return false;
//    }
//}

void myBaseDataModel::addItem()
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.append(myBaseDataItem(Ptemp));
    Ptemp.clear();
    endInsertRows();
}

void myBaseDataModel::getPoint(float x, float y)
{
    P.setX(x);
    P.setY(y);
    Ptemp<<P;
}

QHash<int, QByteArray> myBaseDataModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[pointsRole] = "pointList";
    return roles;
}
