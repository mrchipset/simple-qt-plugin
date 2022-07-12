#include "plugin_widget.h"

#include <QLabel>
#include <QSpinBox>

PluginWidget::PluginWidget(QObject* parent) : QObject(parent)
{

}

QLabel* PluginWidget::CreateQLabel(QWidget* parent)
{
    QLabel* label = new QLabel(parent);
    return label;
}

QSpinBox* PluginWidget::CreateQSpinBox(QWidget* parent)
{
    QSpinBox* spBox = new QSpinBox(parent);
    return spBox;
}
