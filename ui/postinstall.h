#ifndef POSTINSTALL_H
#define POSTINSTALL_H

#include <QProcess>
#include <QWidget>
#include <installationstep.h>

namespace Ui {
class PostInstall;
}

class PostInstall : public InstallationStep
{
    Q_OBJECT

public:
    explicit PostInstall(QWidget *parent = nullptr);
    ~PostInstall();

    QString title();
    QString desc();
    void onStart();

private:
    Ui::PostInstall *ui;
    QProcess *scriptProcess;

public slots:
    void retranslate();

signals:
    void stepFinished();
    void back();

};

#endif // POSTINSTALL_H
