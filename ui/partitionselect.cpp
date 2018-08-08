#include "partitionselect.h"

#include <ui_partitionselect.h>

PartitionSelect::PartitionSelect(QWidget *parent) :
    InstallationStep (parent),
    ui(new Ui::PartitionSelect)
{
    ui->setupUi(this);
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
