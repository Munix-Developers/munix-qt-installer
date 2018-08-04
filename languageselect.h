#ifndef LANGUAGESELECT_H
#define LANGUAGESELECT_H

#include "installationstep.h"

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

private:
    Ui::LanguageSelect *ui;
    void genLangList();
};

#endif // LANGUAGESELECT_H
