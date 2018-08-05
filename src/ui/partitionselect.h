#ifndef PARTITIONSELECT_H
#define PARTITIONSELECT_H

#include <QWidget>

#include <headers/installationstep.h>

namespace Ui {
class PartitionSelect;
}

class PartitionSelect : public InstallationStep
{
    Q_OBJECT

public:
    explicit PartitionSelect(QWidget *parent = nullptr);
    ~PartitionSelect();

    QString title();
    QString desc();
private:
    Ui::PartitionSelect *ui;

public slots:
    void retranslate();

signals:
    void stepFinished();
    void back();
private slots:
    void on_back_released();
};

#endif // PARTITIONSELECT_H
