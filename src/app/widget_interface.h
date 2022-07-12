#ifndef WIDGET_INTERFACE_H
#define WIDGET_INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QSpinBox>

class WidgetInterface
{
public:
    virtual ~WidgetInterface() {};

    virtual QLabel* CreateQLabel(QWidget* parent) = 0;
    virtual QSpinBox* CreateQSpinBox(QWidget* parent) = 0;
};

QT_BEGIN_NAMESPACE

#define WidgetInterface_iid "org.mrchip.SimplePlugin.WidgetInterface"
Q_DECLARE_INTERFACE(WidgetInterface, WidgetInterface_iid)
QT_END_NAMESPACE
#endif