
add_library(plugin_thread SHARED plugin_thread.cc plugin_thread.h)
target_link_libraries(plugin_thread PRIVATE Qt5::Core)