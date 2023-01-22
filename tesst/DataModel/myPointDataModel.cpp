#include "myPointDataModel.h"

//---------------------class myBaseDataItem ---------------------------
myPointItem::myPointItem(const float &x, const float &y)
{
    this->x = x;
    this->y = y;
};

float myPointItem::getX() const
{
    return this->x;
}

float myPointItem::getY() const
{
    return this->y;
}

//bool myPointItem::setX(const float &x)
//{
//    if(this->x == x)
//    {
//        return false;
//    }

//    this->x = x;
//    return true;
//}

//bool myPointItem::setY(const float &y)
//{
//    if(this->y == y)
//    {
//        return false;
//    }
//    this->y = y;
//    return true;
//}

//---------------------class myBaseDataItem ---------------------------
myPointDataModel::myPointDataModel(QObject *parent):QAbstractListModel(parent)
{
    Q_UNUSED(parent)
}

int myPointDataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.length();
}
QVariant myPointDataModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }
    const myPointItem &item = m_data[index.row()];
    switch (role)
    {
    case xRole:
        return item.getX();
    case yRole:
        return item.getY();
    default:
        return QVariant();
    }
}

//bool myPointDataModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    if(!index.isValid()){
//        return false;
//    }
//    myPointItem &item = m_data[index.row()];
//    switch (role)
//    {
//        case xRole:
//            return item.setX(value.toFloat());
//        case yRole:
//            return item.setY(value.toFloat());
//        default:
//            return false;
//    }
//}

void myPointDataModel::addItem(float x, float y)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.append(myPointItem(x,y));
    endInsertRows();
}

QHash<int, QByteArray> myPointDataModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[xRole] = "xn";
    roles[yRole] = "yn";
    return roles;
}
