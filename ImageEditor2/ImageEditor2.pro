QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aa.cpp \
    effectmenu.cpp \
    effects.cpp \
    effectsliders.cpp \
    fileinform.cpp \
    histogramequalization.cpp \
    linearfiltering.cpp \
    linerfilter.cpp \
    logwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    morphological.cpp \
    morphologicaltransformations.cpp \
    qcustomplot.cpp \
    settings.cpp \
    ssaa.cpp \
    symmetricinvers.cpp

HEADERS += \
    FileDailog.h \
    aa.h \
    effectmenu.h \
    effects.h \
    effectsliders.h \
    fileinform.h \
    histogramequalization.h \
    linearfiltering.h \
    linerfilter.h \
    logwindow.h \
    mainwindow.h \
    morphological.h \
    morphologicaltransformations.h \
    qcustomplot.h \
    settings.h \
    ssaa.h \
    symmetricinvers.h

FORMS += \
    aa.ui \
    effectmenu.ui \
    effectsliders.ui \
    fileinform.ui \
    histogramequalization.ui \
    linearfiltering.ui \
    logwindow.ui \
    mainwindow.ui \
    morphologicaltransformations.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
