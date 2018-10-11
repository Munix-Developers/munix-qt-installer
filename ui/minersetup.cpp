#include "minersetup.h"
#include "ui_minersetup.h"

MinerSetup::MinerSetup(QWidget *parent) :
    InstallationStep (parent),
    ui(new Ui::MinerSetup)
{
    ui->setupUi(this);
}

MinerSetup::~MinerSetup()
{
    delete ui;
}

QString MinerSetup::title()
{
    return tr("Miner Setup");
}

QString MinerSetup::desc()
{
    return tr("Please configure the desired miner, you can open a browser window for getting pool information.");
}

void MinerSetup::retranslate()
{
    ui->retranslateUi(this);
}
