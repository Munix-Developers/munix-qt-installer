#include "languageselect.h"
#include "mainwindow.h"
#include "installationstep.h"
#include "ui_mainwindow.h"

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
    // TODO: this is fixed, need to receive from cmd line
    connect(ui->languageselect, SIGNAL(langChanged(QString)),
                     this, SLOT(loadLanguage(QString)));
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
    InstallationStep *step = qobject_cast<InstallationStep*>(ui->installSteps->currentWidget());

    ui->labelCurrentStep->setText(step->title());
    ui->labelStepDescription->setText(step->desc());
}

void MainWindow::loadLanguage(QString langCode)
{
    local_translator->load(QString(":/translations/%1.qm").arg(langCode));
    QCoreApplication::installTranslator(local_translator);
    ui->retranslateUi(this);

    updateTitles();
}
