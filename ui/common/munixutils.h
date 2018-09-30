#ifndef MUNIXUTILS_H
#define MUNIXUTILS_H

#include <QProcess>
#include <QTemporaryFile>

class MunixUtils
{
public:
    MunixUtils();

    static QTemporaryFile *GetScriptTempFile(QString scriptName);
    static void SaveToChroot(QString resourceName);
private:
    static QFile *GetScriptFile(QString fileName);
};

#endif // MUNIXUTILS_H
