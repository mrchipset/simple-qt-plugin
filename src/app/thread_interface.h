#ifndef THREAD_INTERFACE_H
#define THREAD_INTERFACE_H

#include <QVector>
class ThreadInterface 
{
public:
    virtual ~ThreadInterface() {}
    virtual int add(int a, int b) = 0;
    virtual void multiply(int a, int b, int& c) = 0;

    virtual void sum(const QVector<double>& arr, double& sum) = 0;
    virtual void sum_async(const QVector<double>& arr) = 0;
    virtual bool isSumOk() = 0;
    virtual double getAsyncSum() = 0;
};

QT_BEGIN_NAMESPACE

#define ThreadInterface_iid "org.mrchip.SimplePlugin.ThreadInterface"

Q_DECLARE_INTERFACE(ThreadInterface, ThreadInterface_iid)
QT_END_NAMESPACE
#endif