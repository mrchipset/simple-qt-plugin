#ifndef PLUGIN_THREAD_H
#define PLUGIN_THREAD_H

#include <QThread>
#include "thread_interface.h"

class PluginThread : public QThread, public ThreadInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.mrchip.SimplePlugin.ThreadInterface" FILE "pluginthread.json")
    Q_INTERFACES(ThreadInterface)

public:
    PluginThread(QObject* parent=nullptr);
    virtual int add(int a, int b) override;
    virtual void multiply(int a, int b, int& c) override;

    virtual void sum(const QVector<double>& arr, double& sum) override;
    virtual void sum_async(const QVector<double>& arr) override;
    virtual bool isSumOk() override;
    virtual double getAsyncSum() override;
private:
    QVector<double> mArrBuffer;
    double mResult;
    bool mResultOk;
protected:
    virtual void run() override;
};

#endif