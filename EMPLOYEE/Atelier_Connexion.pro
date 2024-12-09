#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql multimedia multimediawidgets printsupport charts network
QT +=svg
QT +=serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
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
    arduino.cpp \
    caissedialog.cpp \
    calendarwidget.cpp \
    clients.cpp \
    commande.cpp \
    emailsender.cpp \
    generateurpdf.cpp \
    gestionemployee.cpp \
    historiquedialog.cpp \
    livraison.cpp \
    login.cpp \
        main.cpp \
    connection.cpp \
    messagerie.cpp \
    pageclient.cpp \
    pagecom.cpp \
    pagecommand.cpp \
    pageemp.cpp \
    pagelivr.cpp \
    pagepromotion.cpp \
    promotion.cpp \
    qrcode.cpp \
    smtp.cpp \
    todolist.cpp

HEADERS += \
    arduino.h \
    caissedialog.h \
    calendarwidget.h \
    clients.h \
    commande.h \
    emailsender.h \
    generateurpdf.h \
    gestionemployee.h \
    historiquedialog.h \
    livraison.h \
    login.h \
    connection.h \
    messagerie.h \
    pageclient.h \
    pagecom.h \
    pagecommand.h \
    pageemp.h \
    pagelivr.h \
    pagepromotion.h \
    promotion.h \
    qrcode.h \
    smtp.h \
    todolist.h

FORMS += \
        caissedialog.ui \
        historiquedialog.ui \
        login.ui \
        pageclient.ui \
        pagecom.ui \
        pagecommand.ui \
        pageemp.ui \
        pagelivr.ui \
        pagepromotion.ui \
        todolist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \


DISTFILES += \
