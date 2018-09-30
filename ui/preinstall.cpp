#include "preinstall.h"
#include "ui_preinstall.h"

#include <installationstep.h>
#include <installsettings.h>
#include <munixutils.h>

#include <QDebug>

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
    InstallSettings::getInstance().sendToSystem(false);

    auto args = new QStringList();
    *args << "--geometry=80x24-130-100";
    *args << "-e";
    auto script = MunixUtils::GetScriptTempFile("pre-install.sh");

    QString cmd = script->fileName();
    script->setAutoRemove(false);
    script->close();
    delete script;
    *args << cmd;

    scriptProcess = new QProcess(this);
    connect(scriptProcess , SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(onInstallFinished(int, QProcess::ExitStatus)));
    scriptProcess->start("/usr/bin/xfce4-terminal", *args);
}

void PreInstall::retranslate()
{
    ui->retranslateUi(this);
}

void PreInstall::onInstallFinished(int retVal, QProcess::ExitStatus status) {
    ui->next->setEnabled(true);
}
