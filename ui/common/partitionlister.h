#ifndef PARTITIONLISTER_H
#define PARTITIONLISTER_H

#include <QStandardItemModel>
#include <QString>
#include <QTreeWidget>

class PartitionLister
{
public:
    PartitionLister();
    void devicesToTreeWidget(QTreeWidget *tree, QLocale locale);
private:
    long long getBytesDevSize(QString device);
};

#endif // PARTITIONLISTER_H
