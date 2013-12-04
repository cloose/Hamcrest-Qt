#
# Hamcrest-Qt library
#
# Github: https://github.com/cloose/Hamcrest-Qt
#
QT       -= gui
QT       += testlib

TARGET = hamcrestqtcore
TEMPLATE = lib

CONFIG += exceptions c++11

SOURCES += \
    basedescription.cpp \
    description.cpp \
    matcherassert.cpp \
    stringdescription.cpp

HEADERS += \
    basedescription.h \
    basematcher.h \
    description.h \
    matcher.h \
    matcherassert.h \
    selfdescribing.h \
    stringdescription.h \
    tostring_p.h \
    matcher/allof.h \
    matcher/areequal_p.h \
    matcher/is.h \
    matcher/isequal.h \
    matcher/isnot.h \
    diagnosingmatcher.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
