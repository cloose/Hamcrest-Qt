#
# Unit Test Project for Hamcrest-Qt library
#
# Github: https://github.com/cloose/Hamcrest-Qt
#
QT       += testlib
QT       -= gui

TARGET = unittest
CONFIG   += console exceptions testcase
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    basedescriptiontest.cpp \
    basematchertest.cpp \
    isequaltest.cpp \
    matcherasserttest.cpp

HEADERS += \
    basedescriptiontest.h \
    basematchertest.h \
    isequaltest.h \
    matcherasserttest.h \
    abstractmatcher.h

##################################################
# Dependencies
##################################################

#
# Hamcrest-Qt core library
#
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../core/release/ -lhamcrestqtcore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../core/debug/ -lhamcrestqtcore
else:unix: LIBS += -L$$OUT_PWD/../../core/ -lhamcrestqtcore

INCLUDEPATH += $$PWD/../../core
DEPENDPATH += $$PWD/../../core
