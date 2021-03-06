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
    stringdescription.cpp \
    matcher/stringcontains.cpp \
    matcher/stringendswith.cpp \
    matcher/stringstartswith.cpp

HEADERS += \
    basedescription.h \
    basematcher.h \
    description.h \
    diagnosingmatcher.h \
    matcher.h \
    matcherassert.h \
    selfdescribing.h \
    stringdescription.h \
    tostring_p.h \
    matcher/allof.h \
    matcher/anyof.h \
    matcher/areequal_p.h \
    matcher/is.h \
    matcher/isanything.h \
    matcher/isequal.h \
    matcher/isnot.h \
    matcher/shortcutcombination.h \
    matcher/stringcontains.h \
    matcher/stringendswith.h \
    matcher/stringstartswith.h \
    matcher/substringmatcher.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
