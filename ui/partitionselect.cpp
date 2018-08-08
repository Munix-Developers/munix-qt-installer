#include "partitionselect.h"

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
    // TODO: may break the checkbox logic?
    if (!checked) {
        ui->deleteEverything->setChecked(true);
    }

    ui->next->setEnabled(true);
}
