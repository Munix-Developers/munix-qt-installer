#include "partitionlister.h"

#include <QDirIterator>
#include <QFile>
#include <QLocale>
#include <QDebug>
#include <QTreeWidget>

PartitionLister::PartitionLister()
{

}

long long int PartitionLister::getBytesDevSize(QString device) {
    // Open device size descriptor
    QFile devSize(device.append("/size"));
    devSize.open(QIODevice::ReadOnly);

    // Device bytes is a long long
    // https://github.com/karelzak/util-linux/blob/05541825553524e2ac353eb6c62c8b5ad049de24/misc-utils/lsblk.c#L1284
    long long int size = devSize.readAll().trimmed().toLongLong() << 9;

    devSize.close();
    return size;
}

// TODO: Fix sorting based on size: https://stackoverflow.com/questions/363200/is-it-possible-to-sort-numbers-in-a-qtreewidget-column
void PartitionLister::devicesToTreeWidget(QTreeWidget *tree, QLocale locale) {
    // Clears the tree
    tree->clear();

    int devCount = 0;

    // Iterates over all the block devices (disks)
    QDirIterator devs("/sys/block/", QStringList() << "sd*", QDir::NoFilter, QDirIterator::Subdirectories);
    while (devs.hasNext()) {
        // Get device name and information
        QFile device(devs.next());
        QFileInfo devInfo(device);
        QString devName = devInfo.fileName();
        long long int devBytes = getBytesDevSize(device.fileName());
        QString devSize = locale.formattedDataSize(devBytes, 1, QLocale::DataSizeSIFormat);

        // Creates the treeItem and add to the tree
        // TODO: move to a private function
        QTreeWidgetItem *devItem = new QTreeWidgetItem();
        devItem->setText(0, devName);
        devItem->setText(1, devSize);
        devItem->setFlags(Qt::ItemFlag::ItemIsEnabled);
        devItem->setData(1, Qt::UserRole, devBytes);
        tree->insertTopLevelItem(devCount++, devItem);

        //qDebug() << devName << ": " << devSize;

        // Iterates over all partitions
        QDirIterator partitions(device.fileName(), QStringList() << devName.append('*'), QDir::NoFilter, QDirIterator::Subdirectories);
        while (partitions.hasNext()) {
            // Get partition info based on the device above
            QFile part(partitions.next());
            QFileInfo partInfo(part.fileName());
            QString partName = partInfo.fileName();
            long long int partBytes = getBytesDevSize(part.fileName());
            QString partSize = locale.formattedDataSize(partBytes, 1, QLocale::DataSizeSIFormat);

            // Creates the treeItem and add to the deviceList
            // TODO: move to a private function
            QTreeWidgetItem *partItem = new QTreeWidgetItem();
            partItem->setText(0, partName);
            partItem->setText(1, partSize);
            partItem->setData(1, Qt::UserRole, partBytes);
            devItem->addChild(partItem);

            //qDebug() << partName << ": " << partSize;

            part.close();
        }

        device.close();
    }

    // Finally, expand all and sort
    tree->expandAll();
    tree->sortItems(0, Qt::AscendingOrder);
}

