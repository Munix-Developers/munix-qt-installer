#include "languageselect.h"
#include "ui_languageselect.h"

LanguageSelect::LanguageSelect(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LanguageSelect)
{
    ui->setupUi(this);
}

LanguageSelect::~LanguageSelect()
{
    delete ui;
}
