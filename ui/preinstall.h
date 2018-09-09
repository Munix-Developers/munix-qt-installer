#ifndef PREINSTALL_H
#define PREINSTALL_H

#include <QProcess>
#include <QWidget>
#include <installationstep.h>

namespace Ui {
class PreInstall;
}

class PreInstall : public InstallationStep
{
    Q_OBJECT

public:
    explicit PreInstall(QWidget *parent = nullptr);
    ~PreInstall();

    QString title();
    QString desc();
    void onStart();

private:
    Ui::PreInstall *ui;
    QProcess *scriptProcess;

public slots:
    void retranslate();

private slots:
    void scriptOutput();

signals:
    void stepFinished();
    void back();

};
#endif // PREINSTALL_H
