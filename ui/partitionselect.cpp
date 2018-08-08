#include "partitionselect.h"

#include <QDirIterator>
#include <QDebug>
#include <ui_partitionselect.h>

PartitionSelect::PartitionSelect(QWidget *parent) :
    InstallationStep (parent),
    ui(new Ui::PartitionSelect)
{
    ui->setupUi(this);

    connect(ui->deleteEverything, SIGNAL(toggled(bool)),
            this, SLOT(onCheckboxToggled(bool)));
}

PartitionSelect::~PartitionSelect()
{
    delete ui;
}

QString PartitionSelect::title()
{
    return tr("Installation Type");
}

QString PartitionSelect::desc()
{
    return tr("Here you can select what disk partition will be used for the installation. Currently there isn't support for dual-boot.");
}

void PartitionSelect::retranslate()
{
    ui->retranslateUi(this);
}

void PartitionSelect::on_back_released()
{
    back();
}

void PartitionSelect::onCheckboxToggled(bool checked)
{
    // TODO: may break the exclusive checkbox logic?
    if (!checked) {
        ui->deleteEverything->setChecked(true);
    }

    ui->next->setEnabled(true);
}

// TODO: move the implementation of this to another class
long long int PartitionSelect::getDevSize(QString device) {
    // Open device size descriptor
    QFile devSize(device.append("/size"));
    devSize.open(QIODevice::ReadOnly);

    // Device bytes is in long long
    return devSize.readAll().trimmed().toLongLong();
}

void PartitionSelect::on_next_released()
{
    // Iterates over all the block devices (disks)
    QDirIterator devs("/sys/block/", QStringList() << "sd*", QDir::NoFilter, QDirIterator::Subdirectories);

    QLocale locale = this->locale();

    while (devs.hasNext()) {
        // Get device name
        QFile device(devs.next());
        QFileInfo devInfo(device);
        QString devName = devInfo.fileName();

        qDebug() << devName << ": " << locale.formattedDataSize(getDevSize(device.fileName()));

        QDirIterator partitions(device.fileName(), QStringList() << devName.append('*'), QDir::NoFilter, QDirIterator::Subdirectories);

        while (partitions.hasNext()) {
            QFile part(partitions.next());
            QFileInfo partInfo(part.fileName());
            QString partName = partInfo.fileName();

            qDebug() << partName << ": " << locale.formattedDataSize(getDevSize(part.fileName()), 1, QLocale::DataSizeSIFormat);
        }
    }
}
