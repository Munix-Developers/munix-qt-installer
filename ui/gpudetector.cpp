#include "gpudetector.h"
#include "ui_gpudetector.h"

GpuDetector::GpuDetector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GpuDetector)
{
    ui->setupUi(this);
}

GpuDetector::~GpuDetector()
{
    delete ui;
}
