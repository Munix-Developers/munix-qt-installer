#include "languageselect.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Disable rezising
    setFixedSize(800, 600);

    // Add languageSelect to install steps
    LanguageSelect(ui->installSteps);
}

MainWindow::~MainWindow()
{
    delete ui;
}
