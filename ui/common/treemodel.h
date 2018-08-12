#ifndef TREEMODEL_H
#define TREEMODEL_H

#include "treeitem.h"

#include <QAbstractItemModel>
#include <QWidget>

class TreeModel : public QAbstractItemModel
{
public:
    explicit TreeModel(QObject *parent = nullptr);
    ~TreeModel() override;

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    void setupModelData(const QStringList &lines, TreeItem *item);

    TreeItem *rootItem;
};

#endif // TREEMODEL_H
