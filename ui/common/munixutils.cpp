#include "munixutils.h"

#include <QTemporaryFile>
#include <qfile.h>

MunixUtils::MunixUtils()
{

}

QTemporaryFile *MunixUtils::GetScriptTempFile(QString scriptName)
{
    // Find script file
    QString script(":/scripts/");
    script.append(scriptName);
    QFile file(script);

    // Generate a temp file from the resource
    auto tempFile = new QTemporaryFile(scriptName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    tempFile->open();
    tempFile->write(file.readAll());
    tempFile->setPermissions(QFile::ExeOwner | QFile::ReadOwner | QFile::WriteOwner);
    tempFile->flush();

    file.close();

    return tempFile;
}
