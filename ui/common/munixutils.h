#ifndef MUNIXUTILS_H
#define MUNIXUTILS_H

#include <QProcess>

class MunixUtils
{
public:
    MunixUtils();

    static void SetupScriptArgs(QStringList *args, QString scriptName);
};

#endif // MUNIXUTILS_H
