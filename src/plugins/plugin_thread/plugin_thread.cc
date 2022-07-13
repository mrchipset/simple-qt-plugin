#include "plugin_thread.h"
#include <numeric>

PluginThread::PluginThread(QObject* parent) : QThread(parent),
    mResultOk(false)
{

}

int PluginThread::add(int a, int b)
{
    return a + b;
}

void PluginThread::multiply(int a, int b, int& c)
{
    c = a * b;
}

void PluginThread::sum(const QVector<double>& arr, double& sum)
{
    sum = std::accumulate(arr.begin(), arr.end() , 0.0);
}

void PluginThread::sum_async(const QVector<double>& arr)
{
    if(isRunning()) {
        return;
    }

    mArrBuffer = arr;
    mResultOk = false;
    start();
}

bool PluginThread::isSumOk()
{
    return mResultOk;
}

double PluginThread::getAsyncSum()
{
    return mResult;
}

void PluginThread::run()
{
    QThread::msleep(1000);
    mResult = std::accumulate(mArrBuffer.begin(), mArrBuffer.end(), 0.0);
    mResultOk = true;
}