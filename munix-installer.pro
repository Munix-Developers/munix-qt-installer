#-------------------------------------------------
#
# Project created by QtCreator 2018-08-03T22:56:30
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = munix-installer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        ui/main.cpp \
        ui/mainwindow.cpp \
    ui/languageselect.cpp \
    ui/partitionselect.cpp \
    ui/common/installationstep.cpp \
    ui/common/partitionlister.cpp \
    ui/common/installsettings.cpp \
    ui/common/munixutils.cpp \
    ui/preinstall.cpp \
    ui/postinstall.cpp

HEADERS += \
        ui/mainwindow.h \
    ui/languageselect.h \
    ui/common/installationstep.h \
    ui/partitionselect.h \
    ui/common/partitionlister.h \
    ui/common/installsettings.h \
    ui/common/munixutils.h \
    ui/preinstall.h \
    ui/postinstall.h

FORMS += \
        forms/mainwindow.ui \
    forms/languageselect.ui \
    forms/partitionselect.ui \
    forms/preinstall.ui \
    forms/postinstall.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/translations/translations.qrc \
    resources/scripts/scripts.qrc

INCLUDEPATH += ui
INCLUDEPATH += ui/common

