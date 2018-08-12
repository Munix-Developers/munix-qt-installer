#ifndef LANGUAGESELECT_H
#define LANGUAGESELECT_H

#include <QListWidgetItem>
#include <QWidget>

#include "ui/common/installationstep.h"

namespace Ui {
class LanguageSelect;
}

class LanguageSelect : public InstallationStep
{
    Q_OBJECT

public:
    explicit LanguageSelect(QWidget *parent = nullptr);
    ~LanguageSelect();

    QString title();
    QString desc();

signals:
    void langChanged(QString langCode);
    void stepFinished();

private slots:
    void on_listLanguageSelect_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void retranslate();

    void on_nextStep_clicked();

private:
    Ui::LanguageSelect *ui;
    void genLangList();

};

#endif // LANGUAGESELECT_H
