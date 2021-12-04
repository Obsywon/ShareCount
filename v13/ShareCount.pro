#-------------------------------------------------
#
# Project created by QtCreator 2021-11-10T14:07:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShareCount
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


SOURCES += \
    Database.cpp \
    gestioncomptes.cpp \
    main.cpp \
    Model.cpp \
    Groupe.cpp \
    Launch.cpp \
    Connect.cpp \
    AjoutEvent.cpp \
    FabriqueID.cpp \
    MainWindow.cpp \
    AjoutGroupe.cpp \
    Inscription.cpp \
    Utilisateur.cpp \
    GestionEvents.cpp \
    GestionGroupes.cpp \
    GestionnaireComptes.cpp \
    GestionnaireGroupes.cpp \
    GestionnaireEvenement.cpp \
    Evenement.cpp

HEADERS += \
    Database.hpp \
    Model.hpp \
    Groupe.hpp \
    Launch.hpp \
    Connect.hpp \
    AjoutEvent.hpp \
    FabriqueID.hpp \
    MainWindow.hpp \
    AjoutGroupe.hpp \
    Inscription.hpp \
    Utilisateur.hpp \
    GestionEvents.hpp \
    GestionGroupes.hpp \
    GestionnaireComptes.hpp \
    GestionnaireGroupes.hpp \
    GestionnaireEvenement.hpp \
    Evenement.hpp \
    gestioncomptes.hpp

FORMS += \
        gestioncomptes.ui \
        mainwindow.ui \
        launch.ui \
        connect.ui \
        ajoutevent.ui \
        ajoutgroupe.ui \
        inscription.ui \
        gestionevents.ui \
        gestiongroupes.ui
        
