#ifndef LANGUAGESELECT_H
#define LANGUAGESELECT_H

#include "installationstep.h"

#include <QListWidgetItem>
#include <QWidget>

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
