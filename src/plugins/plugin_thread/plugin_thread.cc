#include "plugin_thread.h"
#include <numeric>

PluginThread::PluginThread(QObject* parent) : QThread(parent)
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

}

bool PluginThread::isSumOk()
{
    return true;
}

double PluginThread::getAsyncSum()
{
    return 0.0;
}

void PluginThread::run()
{

}