#include "languageselect.h"
#include "mainwindow.h"
#include "installationstep.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Disable resizing
    setFixedSize(800, 600);

    // Translate the first step
    updateTitles();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Updates the current step title
 * and description
 */
void MainWindow::updateTitles()
{
    InstallationStep *step = static_cast<InstallationStep*>(ui->installSteps->currentWidget());

    ui->labelCurrentStep->setText(step->title());
    ui->labelStepDescription->setText(step->desc());
}
