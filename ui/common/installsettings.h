#ifndef INSTALLSETTINGS_H
#define INSTALLSETTINGS_H

#include <QString>



class InstallSettings
{
public:
    static InstallSettings& getInstance()
    {
        static InstallSettings instance;
        return instance;
    }

    QString getCountryCode() const;
    void setCountryCode(const QString &value);

    QString getLangCode() const;
    void setLangCode(const QString &value);

    QString getDevName() const;
    void setDevName(const QString &value);

    QString getLocaleCode() const;

    // Used to setup env. vars based on the install settings
    void sendToSystem(bool chroot);

private:
    InstallSettings() {}
    InstallSettings(InstallSettings const&);
    void operator=(InstallSettings const&);

    // US BR ES
    QString countryCode;
    // en pt sp
    QString langCode;
    // Device where Munix will be installed (eg. sda sdb sdc)
    QString devName;

    void appendSourceVar(QString *sources, QString sourceName, QString value);
};

#endif // INSTALLSETTINGS_H
