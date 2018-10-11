#include "ui/languageselect.h"
#include "ui/mainwindow.h"
#include "ui/common/installationstep.h"
#include "ui/common/installsettings.h"

#include <ui_mainwindow.h>
#include <QDebug>
#include <QCloseEvent>
#include <gpufinder.h>

MainWindow::MainWindow(QWidget *parent, QTranslator *translator) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Disable resizing
    setFixedSize(800, 600);

    // Always on top
    setWindowFlags(Qt::WindowStaysOnTopHint);

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
    connect(this, SIGNAL(langChanged()),
            ui->preInstall, SLOT(retranslate()));
    connect(this, SIGNAL(langChanged()),
            ui->minerSetup, SLOT(retranslate()));
    connect(this, SIGNAL(langChanged()),
            ui->postInstall, SLOT(retranslate()));

    // Next step buttons events
    connect(ui->languageselect, SIGNAL(stepFinished()),
            this, SLOT(nextStep()));
    connect(ui->partitionSelect, SIGNAL(stepFinished()),
            this, SLOT(nextStep()));
    connect(ui->preInstall, SIGNAL(stepFinished()),
            this, SLOT(nextStep()));

    // Back buttons events
    connect(ui->partitionSelect, SIGNAL(back()),
            this, SLOT(previousStep()));

    // TODO: DELETE
    auto gpuFind = new GpuFinder();

    gpuFind->findGPUs();
}

MainWindow::~MainWindow()
{
    delete local_translator;
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    event->ignore();
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

}

void MainWindow::nextStep()
{
    int nextStep = (ui->installsteps->currentIndex() + 1) % ui->installsteps->count();

    ui->installsteps->setCurrentIndex(nextStep);

    updateTitles();

    InstallationStep *step = qobject_cast<InstallationStep*>(ui->installsteps->currentWidget());

    step->onStart();
}

void MainWindow::previousStep()
{
    int nextStep = ui->installsteps->currentIndex() - 1;

    nextStep = nextStep < 0 ? 0:nextStep;

    ui->installsteps->setCurrentIndex(nextStep);

    updateTitles();
}
