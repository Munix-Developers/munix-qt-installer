#include "postinstall.h"
#include "ui_postinstall.h"

#include <installsettings.h>
#include <munixutils.h>

PostInstall::PostInstall(QWidget *parent) :
    InstallationStep (parent),
    ui(new Ui::PostInstall)
{
    ui->setupUi(this);
}

PostInstall::~PostInstall()
{
    delete ui;
}

QString PostInstall::title()
{
    return tr("Post Installation");
}

QString PostInstall::desc()
{
    return tr("Munix will now setup the miner...");
}

void PostInstall::retranslate()
{
    ui->retranslateUi(this);
}

void PostInstall::onStart()
{
    InstallSettings::getInstance().sendToSystem(true);

    auto args = new QStringList();
    *args << "--geometry=80x24-130-100";
    *args << "-e";
    auto script = MunixUtils::GetScriptTempFile("post-install.sh");

    QString cmd = script->fileName();
    script->setAutoRemove(false);
    script->close();
    delete script;
    *args << cmd;

    MunixUtils::SaveToChroot("post-install-chroot.sh");

    scriptProcess = new QProcess(this);
    scriptProcess->start("/usr/bin/xfce4-terminal", *args);
}
