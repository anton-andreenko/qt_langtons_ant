# qt_langtons_ant.pro

QT += core gui widgets

TARGET = qt_langtons_ant

TEMPLATE = app

CONFIG += c++11

HEADERS += \
    aux_header.hpp \
    main_window.hpp \
    forms/form_load_ant_ai_preset.hpp \
    widgets/widget_paint_area.hpp \
    classes/class_field.hpp \
    classes/class_ant.hpp

SOURCES += \
    main.cpp \
    main_window.cpp \
    main_window_slots.cpp \
    forms/form_load_ant_ai_preset.cpp \
    forms/form_load_ant_ai_preset_slots.cpp \
    widgets/widget_paint_area.cpp \
    classes/class_field.cpp \
    classes/class_ant.cpp

FORMS += \
    main_window.ui \
    forms/form_load_ant_ai_preset.ui

RESOURCES += \
    resources.qrc
