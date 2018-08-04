#ifndef LANGUAGESELECT_H
#define LANGUAGESELECT_H

#include <QWidget>

namespace Ui {
class LanguageSelect;
}

class LanguageSelect : public QWidget
{
    Q_OBJECT

public:
    explicit LanguageSelect(QWidget *parent = nullptr);
    ~LanguageSelect();

private:
    Ui::LanguageSelect *ui;
};

#endif // LANGUAGESELECT_H
