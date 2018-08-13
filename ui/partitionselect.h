#ifndef PARTITIONSELECT_H
#define PARTITIONSELECT_H

#include <QFile>
#include <QTreeWidget>
#include <QWidget>

#include <ui/common/installationstep.h>
#include <ui/common/partitionlister.h>

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

    PartitionLister *partLister;

public slots:
    void retranslate();

signals:
    void stepFinished();
    void back();
private slots:
    void on_back_released();
    void onCheckboxToggled(bool checked);
    void on_next_clicked();
    void on_partitionList_itemSelectionChanged();
    void reloadPartitions();
    void proccessOutput();
};

#endif // PARTITIONSELECT_H
