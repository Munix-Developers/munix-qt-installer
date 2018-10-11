#ifndef GPUFINDER_H
#define GPUFINDER_H

#include <QObject>
#include <QProcess>
#include <QString>


enum GpuType {
    NVIDIA,
    NVIDIA_390,
    NVIDIA_340,
    AMD,

    UNKNOW
};

class Gpu
{
public:
    Gpu(GpuType type, QString model);

    GpuType getType() const;
    void setType(const GpuType &value);

    QString getModel() const;
    void setModel(const QString &value);

    static Gpu getFromStr(QString gpuStr);
    static QList<Gpu> *fromStrList(QStringList strList);

private:
    GpuType type;
    QString model;
};

class GpuFinder : public QObject
{
    Q_OBJECT
public:
    GpuFinder();

    void findGPUs();

public slots:
        void onGpuSearchFinish(int, QProcess::ExitStatus);

signals:
        void gpuSearchFinished(QList<Gpu>*);

private:
    QProcess *procSearchGpus;
};

#endif // GPUFINDER_H
