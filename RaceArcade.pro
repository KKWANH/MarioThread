greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    src/gamethread.h \
    src/utils.h \
    src/view.h

SOURCES += \
    src/gamethread.cpp \
    src/main.cpp \
    src/view.cpp

RESOURCES += \
    resource.qrc
