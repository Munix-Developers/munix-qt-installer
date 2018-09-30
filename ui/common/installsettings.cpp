#include "installsettings.h"

#include <QFile>


QString InstallSettings::getCountryCode() const
{
    return countryCode;
}

void InstallSettings::setCountryCode(const QString &value)
{
    countryCode = value;
}

QString InstallSettings::getLangCode() const
{
    return langCode;
}

void InstallSettings::setLangCode(const QString &value)
{
    langCode = value;
}

QString InstallSettings::getDevName() const
{
    return devName;
}

void InstallSettings::setDevName(const QString &value)
{
    devName = value;
}

QString InstallSettings::getLocaleCode() const
{
    return QString("%1_%2").arg(langCode, countryCode);
}

void InstallSettings::appendSourceVar(QString *sources, QString sourceName, QString value) {
    sources->append(sourceName.append("="));
    sources->append(value);
    sources->append('\n');
}

void InstallSettings::sendToSystem(bool chroot)
{
    qputenv("MDEVICE", devName.toUtf8());
    qputenv("MCOUNTRY", countryCode.toUtf8());
    qputenv("MLANG", langCode.toUtf8());
    qputenv("MLOCALE", getLocaleCode().toUtf8());

    auto source = new QString();

    appendSourceVar(source, "MDEVICE", devName);
    appendSourceVar(source, "MCOUNTRY", countryCode);
    appendSourceVar(source, "MLANG", langCode);
    appendSourceVar(source, "MLOCALE", getLocaleCode());

    QFile file("/tmp/munix-vars");
    file.open(QFile::WriteOnly);
    file.write(source->toUtf8());
    file.close();

    if (chroot)
    {
        QFile chrootFile("/mnt/munix-vars");
        chrootFile.open(QFile::WriteOnly);
        chrootFile.write(source->toUtf8());
        chrootFile.close();
    }
}
