#include "ui/common/installationstep.h"

InstallationStep::InstallationStep(QWidget *parent) : QWidget(parent)
{ }

QString InstallationStep::title()
{
    return "";
}

QString InstallationStep::desc()
{
    return "";
}

void InstallationStep::onStart()
{

}

void InstallationStep::retranslate() {

}
