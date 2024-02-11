#include "mytablemodel.h"
#include "exercise.h"

MyTableModel::MyTableModel()
{
}

MyTableModel::~MyTableModel()
{
    qDeleteAll(exerciseList);
    exerciseList.clear();
}

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return exerciseList.size();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 2;
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        if (index.column() == 0)
            return int(Qt::AlignLeft | Qt::AlignVCenter);
        else
            return int(Qt::AlignRight | Qt::AlignVCenter);
    }

    if (role == Qt::DisplayRole)
    {
        int col{index.column()};
        int row{index.row()};
        if (col==0)
            return exerciseList.at(row)->getData();
        else
            return exerciseList.at(row)->getNum();
    }

    return QVariant();
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Vertical)
        return QVariant();

    switch (section)
    {
    case 0: return QString("Data");   break;
    case 1: return QString("Number"); break;
    default: return QVariant();
    }

    return QVariant();
}

bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role==Qt::EditRole)
    {
        int col{index.column()};
        int row{index.row()};
        switch (col)
        {
        case 0: exerciseList.at(row)->setData(value.toString());   break;
        case 1: exerciseList.at(row)->setNum(value.toInt());       break;
        default: return false;
        }
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{
    if (index.isValid())
        return (Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
    else
        return Qt::NoItemFlags;
}

void MyTableModel::addExercise(Exercise *e)
{
    int row{static_cast<int>(exerciseList.size())};
    beginInsertRows(QModelIndex(), row, row);
    exerciseList.append(e);
    endInsertRows();
}
