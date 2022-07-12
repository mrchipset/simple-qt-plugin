add_library(plugin_widget SHARED plugin_widget.cc plugin_widget.h)
target_link_libraries(plugin_widget PRIVATE Qt5::Widgets Qt5::Core)