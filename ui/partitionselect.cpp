#include "partitionselect.h"

#include <QDirIterator>
#include <QDebug>
#include <ui_partitionselect.h>

#include <ui/common/partitionlister.h>

PartitionSelect::PartitionSelect(QWidget *parent) :
    InstallationStep (parent),
    ui(new Ui::PartitionSelect)
{
    ui->setupUi(this);

    connect(ui->deleteEverything, SIGNAL(toggled(bool)),
            this, SLOT(onCheckboxToggled(bool)));
    connect(ui->reloadPartitions, SIGNAL(clicked()),
            this, SLOT(reloadPartitions()));

    partLister = new PartitionLister();
}

PartitionSelect::~PartitionSelect()
{
    delete partLister;
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
    else {
        // TODO: this isn't dynamic, any other checkbox requires duplicate code
        ui->partitionList->setEnabled(true);
        ui->reloadPartitions->setEnabled(true);
        ui->labelWhereInstall->setEnabled(true);
        reloadPartitions();
    }
}

void PartitionSelect::reloadPartitions()
{
    partLister->devicesToTreeWidget(ui->partitionList, this->locale());
}

void PartitionSelect::on_next_clicked()
{
}

void PartitionSelect::on_partitionList_itemSelectionChanged()
{
    auto list = ui->partitionList->selectedItems();

    if (list.size() > 0) {
        auto selectedPartition = list.first();

        qDebug() << selectedPartition->data(1, Qt::UserRole);

        ui->next->setEnabled(true);
    }
    else {
        ui->next->setEnabled(false);
    }
}
