#
# Hamcrest-Qt library
#
# Github: https://github.com/cloose/Hamcrest-Qt
#
QT       -= gui
QT       += testlib

TARGET = hamcrestqtcore
TEMPLATE = lib

CONFIG += exceptions

SOURCES += \
    basedescription.cpp \
    description.cpp

HEADERS += \
    basedescription.h \
    description.h \
    selfdescribing.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
