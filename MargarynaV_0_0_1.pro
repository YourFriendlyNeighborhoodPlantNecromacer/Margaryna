QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MyWindow.cpp \
    main.cpp \
    tools/ToolFunctions.cpp \
    tools/ToolSettings.cpp \
    tools/fill/FillTool.cpp \
    tools/line/LineTool.cpp \
    tools/pen/PenTool.cpp \
    tools/pen/PenToolSettings.cpp \
    widgets/LabeledSlider.cpp

HEADERS += \
    MyWindow.h \
    tools/Tool.h \
    tools/ToolFunctions.h \
    tools/ToolSettings.h \
    tools/fill/FillTool.h \
    tools/line/LineTool.h \
    tools/pen/PenTool.h \
    tools/pen/PenToolSettings.h \
    widgets/LabeledSlider.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    roadmap
