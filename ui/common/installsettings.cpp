#include "installsettings.h"


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

void InstallSettings::sendToSystem()
{
    qputenv("MDEVICE", devName.toUtf8());
    qputenv("MCOUNTRY", countryCode.toUtf8());
    qputenv("MLANG", langCode.toUtf8());
    qputenv("MLOCALE", getLocaleCode().toUtf8());
}
