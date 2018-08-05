#include <QMessageBox>
#include <iostream>

#include "headers/languageselect.h"
#include <ui_languageselect.h>

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

    langs.insert("en_us", "English (USA)");
    langs.insert("pt_br", "Português (Brasil)");

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
    return tr("Welcome to Munix!");
}

QString LanguageSelect::desc()
{
    return tr("This installation wizard will guide you through the installation process. Start by selecting your language below.");
}

void LanguageSelect::on_listLanguageSelect_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString selectedLang = current->data(Qt::UserRole).toString();
    langChanged(selectedLang);

    ui->retranslateUi(this);
}

void LanguageSelect::on_nextStep_released()
{
    stepFinished();
}
