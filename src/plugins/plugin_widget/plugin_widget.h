#ifndef PLUGIN_WIDGET_H
#define PLUGIN_WIDGET_H

#include <QObject>

#include "widget_interface.h"

class PluginWidget : public QObject, public WidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.mrchip.SimplePlugin.WidgetInterface" FILE "pluginwidget.json")
    Q_INTERFACES(WidgetInterface)

public:
    PluginWidget(QObject* parent = nullptr);

    virtual QLabel* CreateQLabel(QWidget* parent) override;
    virtual QSpinBox* CreateQSpinBox(QWidget* parent) override;
};

#endif