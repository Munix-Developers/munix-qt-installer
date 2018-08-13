#include "ui/languageselect.h"
#include "ui/mainwindow.h"
#include "ui/common/installationstep.h"
#include "ui/common/installsettings.h"

#include <ui_mainwindow.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, QTranslator *translator) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Disable resizing
    setFixedSize(800, 600);

    // Setup the instance of the translator
    local_translator = translator;

    // Load a language
    //loadLanguage("pt_br");

    // Connect the language change event
    // TODO: this is fixed, need to receive lang from cmd line
    connect(ui->languageselect, SIGNAL(langChanged(QString)),
                     this, SLOT(loadLanguage(QString)));

    // This is needed to change strings at runtime
    connect(this, SIGNAL(langChanged()),
            ui->partitionSelect, SLOT(retranslate()));

    // Next step buttons events
    connect(ui->languageselect, SIGNAL(stepFinished()),
            this, SLOT(nextStep()));

    // Back buttons events
    connect(ui->partitionSelect, SIGNAL(back()),
            this, SLOT(previousStep()));
}

MainWindow::~MainWindow()
{
    delete local_translator;
    delete ui;
}

/*
 * Updates the current step title
 * and description
 */
void MainWindow::updateTitles()
{
    InstallationStep *step = qobject_cast<InstallationStep*>(ui->installsteps->currentWidget());

    ui->labelCurrentStep->setText(step->title());
    ui->labelStepDescription->setText(step->desc());
}

void MainWindow::loadLanguage(QString localeCode)
{
    local_translator->load(QString(":/translations/%1.qm").arg(localeCode));
    QCoreApplication::installTranslator(local_translator);
    ui->retranslateUi(this);

    langChanged();

    updateTitles();

    // Send the language to installsettings
    QStringList codes = localeCode.split("_");
    QString langCode = codes.first();
    QString countryCode = codes.last();

    InstallSettings::getInstance().setLangCode(langCode);
    InstallSettings::getInstance().setCountryCode(countryCode);
}

void MainWindow::nextStep()
{
    int nextStep = (ui->installsteps->currentIndex() + 1) % ui->installsteps->count();

    ui->installsteps->setCurrentIndex(nextStep);

    updateTitles();
}

void MainWindow::previousStep()
{
    int nextStep = ui->installsteps->currentIndex() - 1;

    nextStep = nextStep < 0 ? 0:nextStep;

    ui->installsteps->setCurrentIndex(nextStep);

    updateTitles();
}
