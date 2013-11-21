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
    description.cpp \
    stringdescription.cpp

HEADERS += \
    basedescription.h \
    basematcher.h \
    description.h \
    matcher.h \
    selfdescribing.h \
    stringdescription.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
