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
    virtual void onStart();

signals:
    void stepFinished();
    void back();

public slots:
    void retranslate();
};

#endif // INSTALLATIONSTEP_H
