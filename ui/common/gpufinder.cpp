#include "gpufinder.h"

#include <QProcess>
#include <QRegularExpression>

Gpu::Gpu(GpuType type, QString model) {
    this->type = type;
    this->model = model;
}

GpuType Gpu::getType() const
{
    return type;
}

void Gpu::setType(const GpuType &value)
{
    type = value;
}

QString Gpu::getModel() const
{
    return model;
}

void Gpu::setModel(const QString &value)
{
    model = value;
}

Gpu Gpu::getFromStr(QString gpuStr)
{
    auto regModel = new QRegularExpression("\\[(.+)\\]", QRegularExpression::CaseInsensitiveOption);
    auto regModelNbr = new QRegularExpression("GTX\\s+(\\d+)", QRegularExpression::CaseInsensitiveOption);

    GpuType type = GpuType::UNKNOW;
    QString model = "UNKNOW";

    /* NVIDIA */
    // TODO: this doesn't works on all cases
    if (gpuStr.contains("nvidia", Qt::CaseSensitivity::CaseInsensitive)) {
        auto matchModel = regModel->match(gpuStr);
        auto matchModelNbr = regModelNbr->match(gpuStr);

        if (matchModel.hasMatch()) {
            model = matchModel.captured(1);

            // https://wiki.archlinux.org/index.php/NVIDIA
            int modelNbr = matchModelNbr.captured(1).toInt();
            if (modelNbr >= 600) {
                type = GpuType::NVIDIA;
            } else
                if (modelNbr >= 400) {
                    type = GpuType::NVIDIA_390;
                }
                else {
                    type = GpuType::NVIDIA_340;
                }
        }
    }

    return Gpu(type, model);
}

QList<Gpu>* Gpu::fromStrList(QStringList strList)
{
    auto gpuList = new QList<Gpu>();

    foreach(QString gpuStr, strList) {
        if (!gpuStr.isEmpty()) {
            gpuList->append(Gpu::getFromStr(gpuStr));
        }
    }

    return gpuList;
}

GpuFinder::GpuFinder() : QObject ()
{

}

void GpuFinder::findGPUs()
{
    procSearchGpus = new QProcess(this);
    qDebug("Searching for GPU's");

    procSearchGpus->start("bash", QStringList() << "-c" << "cat /home/mat/Documents/temp/test | grep VGA | cut -d: -f3 | cut -d\\( -f1 | sed -e 's/^[[:space:]]*//'");
    connect(procSearchGpus , SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(onGpuSearchFinish(int, QProcess::ExitStatus)));
}

void GpuFinder::onGpuSearchFinish(int id, QProcess::ExitStatus status)
{
    QString gpuStr(procSearchGpus->readAllStandardOutput());

    gpuSearchFinished(Gpu::fromStrList(gpuStr.split('\n')));
}
