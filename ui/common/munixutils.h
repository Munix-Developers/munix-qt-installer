#ifndef MUNIXUTILS_H
#define MUNIXUTILS_H

#include <QProcess>
#include <QTemporaryFile>

class MunixUtils
{
public:
    MunixUtils();

    static QTemporaryFile *GetScriptTempFile(QString scriptName);
};

#endif // MUNIXUTILS_H
