#include "preinstall.h"
#include "ui_preinstall.h"

#include <installationstep.h>
#include <installsettings.h>
#include <munixutils.h>

PreInstall::PreInstall(QWidget *parent) :
    InstallationStep (parent),
    ui(new Ui::PreInstall)
{
    ui->setupUi(this);
}

PreInstall::~PreInstall()
{
    delete ui;
}

QString PreInstall::title()
{
    return tr("Pre Installation");
}

QString PreInstall::desc()
{
    return tr("Relax and wait while the installer setups Munix. This can take some time.");
}

void PreInstall::onStart()
{
    InstallSettings::getInstance().sendToSystem();

    auto args = new QStringList();
    MunixUtils::SetupScriptArgs(args, "debug-env-vars.sh");

    scriptProcess = new QProcess(this);
    connect(scriptProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(scriptOutput()));
    connect(scriptProcess, SIGNAL(readyReadStandardError()), this, SLOT(scriptOutput()));

    scriptProcess->start("/bin/bash", *args);
}

void PreInstall::retranslate()
{
    ui->retranslateUi(this);
}

void PreInstall::scriptOutput()
{
    ui->tty->append(QString(scriptProcess->readAllStandardOutput()));
}
