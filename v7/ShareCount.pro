######################################################################
# Automatically generated by qmake (3.1) Wed Nov 17 13:59:53 2021
######################################################################

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShareCount
TEMPLATE = app

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += Evenement.hpp \
           FabriqueID.hpp \
           GestionnaireComptes.hpp \
           GestionnaireEvenement.hpp \
           GestionnaireGroupes.hpp \
           Groupe.hpp \
           MainWindow.hpp \
           Model.hpp \
           Utilisateur.hpp
FORMS += mainwindow.ui
SOURCES += Evenement.cpp \
           FabriqueID.cpp \
           GestionnaireComptes.cpp \
           GestionnaireEvenement.cpp \
           GestionnaireGroupes.cpp \
           Groupe.cpp \
           main.cpp \
           MainWindow.cpp \
           Model.cpp \
           Utilisateur.cpp
