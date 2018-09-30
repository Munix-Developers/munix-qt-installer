#include "munixutils.h"

#include <QTemporaryFile>
#include <qfile.h>

MunixUtils::MunixUtils()
{

}

QFile *MunixUtils::GetScriptFile(QString fileName) {
    // Find script file
    QString script(":/scripts/");
    script.append(fileName);
    auto file = new QFile (script);

    return file;
}

QTemporaryFile *MunixUtils::GetScriptTempFile(QString scriptName)
{
    auto file = GetScriptFile(scriptName);

    // Generate a temp file from the resource
    auto tempFile = new QTemporaryFile(scriptName);
    file->open(QIODevice::ReadOnly | QIODevice::Text);

    tempFile->open();
    tempFile->write(file->readAll());
    tempFile->setPermissions(QFile::ExeOwner | QFile::ReadOwner | QFile::WriteOwner);
    tempFile->flush();

    file->close();

    return tempFile;
}

void MunixUtils::SaveToChroot(QString resourceName)
{
    auto file = GetScriptFile(resourceName);

    auto chrootFile = new QFile("/mnt/" + resourceName);
    file->open(QIODevice::ReadOnly | QIODevice::Text);

    chrootFile->open(QIODevice::WriteOnly);
    chrootFile->write(file->readAll());
    chrootFile->setPermissions(QFile::ExeOwner | QFile::ReadOwner | QFile::WriteOwner);
    chrootFile->flush();

    file->close();
    chrootFile->close();

    delete file;
    delete chrootFile;
}
