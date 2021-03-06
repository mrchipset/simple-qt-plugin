#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QPluginLoader>
#include <QDir>
#include <QDebug>
#include <QTimer>

#include "thread_interface.h"
#include "widget_interface.h"

ThreadInterface* LoadThreadInterface() {
    QString threadPluginPath = "../../plugins/plugin_thread/Debug";
    QDir d(threadPluginPath);
    qDebug() << d.absoluteFilePath("plugin_thread.dll");
    QPluginLoader pluginLoader(d.absoluteFilePath("plugin_thread.dll"));
    QObject* threadPlugin = pluginLoader.instance();
    if (threadPlugin) {
        ThreadInterface* threadInterface = qobject_cast<ThreadInterface*>(threadPlugin);
        if (threadInterface) {
            return threadInterface;
        }
    }
    pluginLoader.unload();
    return nullptr;
}

WidgetInterface* LoadWidgetInterface() {
    QString widgetPluginPath = "../../plugins/plugin_widget/Debug";
    QDir d(widgetPluginPath);
    qDebug() << d.absoluteFilePath("plugin_widget.dll");
    QPluginLoader pluginLoader(d.absoluteFilePath("plugin_widget.dll"));
    QObject* widgetPlugin = pluginLoader.instance();
    // pluginLoader.unload();
    if (widgetPlugin) {
        WidgetInterface* widgetInterface = qobject_cast<WidgetInterface*>(widgetPlugin);
        if (widgetInterface) {
            return widgetInterface;
        }
    }
    return nullptr;
}

int main(int argc, char** argv) {
    QApplication app(argc, argv);
    QMainWindow window;


    ThreadInterface* threadInterface = LoadThreadInterface();
    if (threadInterface) {
        int sum = threadInterface->add(1, 2);
        qDebug() << "Plugin sum: 1 + 2 =" << sum;
    }

    WidgetInterface* widgetInterface = LoadWidgetInterface();
    if (widgetInterface) {
        QLabel* pLabel = widgetInterface->CreateQLabel(&window);
        pLabel->setText(QObject::tr("Hello, Widget Interface"));
        window.setCentralWidget(pLabel);
        QTimer* timer = new QTimer(pLabel);
        timer->setInterval(10);
        timer->start();
        threadInterface->sum_async({1, 2, 3, 4, 5});
        QObject::connect(timer, &QTimer::timeout, [&](){
            if (threadInterface->isSumOk()) {
                pLabel->setText(QString("Result is: %1").arg(threadInterface->getAsyncSum()));
                timer->stop();
            } else 
            {
                pLabel->setText(QObject::tr("Result is on the way..."));
            }
        });
    }


    window.resize(640, 480);
    window.show();
    return app.exec();
}
