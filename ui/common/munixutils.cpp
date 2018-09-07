#include "munixutils.h"

#include <qfile.h>

MunixUtils::MunixUtils()
{

}

void MunixUtils::SetupScriptArgs(QStringList *args, QString scriptName)
{
    QString script(":/scripts/");
    script.append(scriptName);

    QFile file(script);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    *args << "-c";
    *args << file.readAll();

    file.close();
}
