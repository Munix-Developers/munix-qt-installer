#include "languageselect.h"
#include "ui_languageselect.h"
#include "config.h"

LanguageSelect::LanguageSelect(QWidget *parent) :
    InstallationStep (parent),
    ui(new Ui::LanguageSelect)
{
    ui->setupUi(this);

    // Add language list with it's codes
    genLangList();
}

LanguageSelect::~LanguageSelect()
{
    delete ui;
}

void LanguageSelect::genLangList() {
    QMap<QString, QString> langs;

    langs.insert("en_us", "English");
    langs.insert("pt_br", "Português");

    int row = 0;
    for (auto lang : langs.keys())
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(langs.take(lang));
        item->setData(Qt::UserRole, lang);

        ui->listLanguageSelect->insertItem(row, item);
        row += 1;
    }
}

QString LanguageSelect::title()
{
    return tr("Welcome to the cryptocurrency mining linux!");
}

QString LanguageSelect::desc()
{
    return tr("This installation wizard will guide you through the installation process. Start by selecting your language below.");
}
