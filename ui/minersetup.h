#ifndef MINERSETUP_H
#define MINERSETUP_H

#include <QWidget>
#include <installationstep.h>

namespace Ui {
class MinerSetup;
}

class MinerSetup : public InstallationStep
{
    Q_OBJECT

public:
    explicit MinerSetup(QWidget *parent = nullptr);
    ~MinerSetup();

    QString title();
    QString desc();

private:
    Ui::MinerSetup *ui;

public slots:
    void retranslate();

signals:
    void stepFinished();
    void back();
};

#endif // MINERSETUP_H
