#ifndef LANGUAGESELECT_H
#define LANGUAGESELECT_H

#include <QListWidgetItem>
#include <QWidget>

#include "installationstep.h"

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

private slots:
    void on_listLanguageSelect_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::LanguageSelect *ui;
    void genLangList();

};

#endif // LANGUAGESELECT_H
