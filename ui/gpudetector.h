#ifndef GPUDETECTOR_H
#define GPUDETECTOR_H

#include <QWidget>

namespace Ui {
class GpuDetector;
}

class GpuDetector : public QWidget
{
    Q_OBJECT

public:
    explicit GpuDetector(QWidget *parent = nullptr);
    ~GpuDetector();

private:
    Ui::GpuDetector *ui;
};

#endif // GPUDETECTOR_H
