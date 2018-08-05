#ifndef INSTALLATIONSTEP_H
#define INSTALLATIONSTEP_H

#include <QWidget>

class InstallationStep : public QWidget
{
    Q_OBJECT
public:
    explicit InstallationStep(QWidget *parent = nullptr);

    virtual QString title();
    virtual QString desc();

signals:
    void stepFinished();

public slots:
};

#endif // INSTALLATIONSTEP_H
