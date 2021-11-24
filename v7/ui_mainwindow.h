/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *pages;
    QWidget *launch;
    QPushButton *seconnecter;
    QPushButton *sinscrire;
    QLabel *titre;
    QWidget *connection;
    QLabel *l_Pseudo;
    QLineEdit *co_mdp;
    QLineEdit *co_pseudo;
    QLabel *label_2;
    QLabel *label;
    QPushButton *connecter;
    QLabel *co_err;
    QWidget *inscription;
    QLineEdit *in_mdp;
    QLineEdit *in_pseudo;
    QLabel *label_3;
    QLabel *l_Pseudo_2;
    QLabel *label_4;
    QPushButton *inscrire;
    QLineEdit *in_email;
    QLabel *label_5;
    QLabel *in_erreur;
    QWidget *gestion_groupes;
    QSplitter *splitter;
    QPushButton *b_groupes;
    QPushButton *b_depenses;
    QPushButton *ajout_groupe;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *groupes;
    QWidget *gestion_evenements;
    QListView *gr_events;
    QPushButton *ajout_event;
    QSplitter *splitter_2;
    QPushButton *participants;
    QPushButton *events;
    QPushButton *cagnotte;
    QWidget *ajoutgroupe;
    QLineEdit *nom_groupe;
    QLabel *label_6;
    QPushButton *ok_groupes;
    QWidget *ajoutEvents;
    QPushButton *ok_event;
    QSplitter *splitter_3;
    QLabel *label_8;
    QDateEdit *dateDeb;
    QLabel *label_7;
    QDateEdit *dateFin;
    QSplitter *splitter_4;
    QLabel *label_9;
    QLineEdit *nom_event;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(337, 396);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pages = new QStackedWidget(centralwidget);
        pages->setObjectName(QString::fromUtf8("pages"));
        launch = new QWidget();
        launch->setObjectName(QString::fromUtf8("launch"));
        seconnecter = new QPushButton(launch);
        seconnecter->setObjectName(QString::fromUtf8("seconnecter"));
        seconnecter->setGeometry(QRect(100, 160, 141, 61));
        sinscrire = new QPushButton(launch);
        sinscrire->setObjectName(QString::fromUtf8("sinscrire"));
        sinscrire->setGeometry(QRect(100, 280, 141, 61));
        titre = new QLabel(launch);
        titre->setObjectName(QString::fromUtf8("titre"));
        titre->setGeometry(QRect(0, 30, 341, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        titre->setFont(font);
        titre->setAutoFillBackground(true);
        titre->setScaledContents(false);
        titre->setAlignment(Qt::AlignCenter);
        pages->addWidget(launch);
        connection = new QWidget();
        connection->setObjectName(QString::fromUtf8("connection"));
        l_Pseudo = new QLabel(connection);
        l_Pseudo->setObjectName(QString::fromUtf8("l_Pseudo"));
        l_Pseudo->setGeometry(QRect(50, 130, 111, 51));
        co_mdp = new QLineEdit(connection);
        co_mdp->setObjectName(QString::fromUtf8("co_mdp"));
        co_mdp->setGeometry(QRect(50, 220, 231, 31));
        co_mdp->setEchoMode(QLineEdit::Password);
        co_pseudo = new QLineEdit(connection);
        co_pseudo->setObjectName(QString::fromUtf8("co_pseudo"));
        co_pseudo->setGeometry(QRect(50, 170, 231, 31));
        label_2 = new QLabel(connection);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 200, 121, 16));
        label = new QLabel(connection);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 40, 341, 41));
        label->setFont(font);
        label->setAutoFillBackground(true);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        connecter = new QPushButton(connection);
        connecter->setObjectName(QString::fromUtf8("connecter"));
        connecter->setGeometry(QRect(110, 290, 121, 41));
        co_err = new QLabel(connection);
        co_err->setObjectName(QString::fromUtf8("co_err"));
        co_err->setGeometry(QRect(20, 340, 311, 16));
        co_err->setScaledContents(true);
        pages->addWidget(connection);
        inscription = new QWidget();
        inscription->setObjectName(QString::fromUtf8("inscription"));
        in_mdp = new QLineEdit(inscription);
        in_mdp->setObjectName(QString::fromUtf8("in_mdp"));
        in_mdp->setGeometry(QRect(50, 230, 231, 31));
        in_mdp->setEchoMode(QLineEdit::Password);
        in_pseudo = new QLineEdit(inscription);
        in_pseudo->setObjectName(QString::fromUtf8("in_pseudo"));
        in_pseudo->setGeometry(QRect(50, 180, 231, 31));
        label_3 = new QLabel(inscription);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 210, 121, 16));
        l_Pseudo_2 = new QLabel(inscription);
        l_Pseudo_2->setObjectName(QString::fromUtf8("l_Pseudo_2"));
        l_Pseudo_2->setGeometry(QRect(50, 140, 111, 51));
        label_4 = new QLabel(inscription);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 20, 341, 41));
        label_4->setFont(font);
        label_4->setAutoFillBackground(true);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);
        inscrire = new QPushButton(inscription);
        inscrire->setObjectName(QString::fromUtf8("inscrire"));
        inscrire->setGeometry(QRect(110, 290, 121, 41));
        in_email = new QLineEdit(inscription);
        in_email->setObjectName(QString::fromUtf8("in_email"));
        in_email->setGeometry(QRect(50, 120, 231, 31));
        label_5 = new QLabel(inscription);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 100, 121, 16));
        in_erreur = new QLabel(inscription);
        in_erreur->setObjectName(QString::fromUtf8("in_erreur"));
        in_erreur->setGeometry(QRect(30, 350, 271, 21));
        in_erreur->setScaledContents(true);
        pages->addWidget(inscription);
        gestion_groupes = new QWidget();
        gestion_groupes->setObjectName(QString::fromUtf8("gestion_groupes"));
        splitter = new QSplitter(gestion_groupes);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 0, 301, 25));
        splitter->setOrientation(Qt::Horizontal);
        b_groupes = new QPushButton(splitter);
        b_groupes->setObjectName(QString::fromUtf8("b_groupes"));
        splitter->addWidget(b_groupes);
        b_depenses = new QPushButton(splitter);
        b_depenses->setObjectName(QString::fromUtf8("b_depenses"));
        splitter->addWidget(b_depenses);
        ajout_groupe = new QPushButton(gestion_groupes);
        ajout_groupe->setObjectName(QString::fromUtf8("ajout_groupe"));
        ajout_groupe->setGeometry(QRect(170, 310, 131, 25));
        verticalLayoutWidget = new QWidget(gestion_groupes);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 40, 271, 241));
        groupes = new QVBoxLayout(verticalLayoutWidget);
        groupes->setObjectName(QString::fromUtf8("groupes"));
        groupes->setSizeConstraint(QLayout::SetFixedSize);
        groupes->setContentsMargins(0, 0, 0, 0);
        pages->addWidget(gestion_groupes);
        gestion_evenements = new QWidget();
        gestion_evenements->setObjectName(QString::fromUtf8("gestion_evenements"));
        gr_events = new QListView(gestion_evenements);
        gr_events->setObjectName(QString::fromUtf8("gr_events"));
        gr_events->setGeometry(QRect(10, 30, 301, 261));
        ajout_event = new QPushButton(gestion_evenements);
        ajout_event->setObjectName(QString::fromUtf8("ajout_event"));
        ajout_event->setGeometry(QRect(180, 310, 131, 25));
        splitter_2 = new QSplitter(gestion_evenements);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(20, 0, 267, 25));
        splitter_2->setOrientation(Qt::Horizontal);
        participants = new QPushButton(splitter_2);
        participants->setObjectName(QString::fromUtf8("participants"));
        splitter_2->addWidget(participants);
        events = new QPushButton(splitter_2);
        events->setObjectName(QString::fromUtf8("events"));
        splitter_2->addWidget(events);
        cagnotte = new QPushButton(splitter_2);
        cagnotte->setObjectName(QString::fromUtf8("cagnotte"));
        splitter_2->addWidget(cagnotte);
        pages->addWidget(gestion_evenements);
        ajoutgroupe = new QWidget();
        ajoutgroupe->setObjectName(QString::fromUtf8("ajoutgroupe"));
        nom_groupe = new QLineEdit(ajoutgroupe);
        nom_groupe->setObjectName(QString::fromUtf8("nom_groupe"));
        nom_groupe->setGeometry(QRect(20, 170, 281, 25));
        label_6 = new QLabel(ajoutgroupe);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 140, 191, 17));
        ok_groupes = new QPushButton(ajoutgroupe);
        ok_groupes->setObjectName(QString::fromUtf8("ok_groupes"));
        ok_groupes->setGeometry(QRect(190, 200, 89, 25));
        pages->addWidget(ajoutgroupe);
        ajoutEvents = new QWidget();
        ajoutEvents->setObjectName(QString::fromUtf8("ajoutEvents"));
        ok_event = new QPushButton(ajoutEvents);
        ok_event->setObjectName(QString::fromUtf8("ok_event"));
        ok_event->setGeometry(QRect(170, 260, 89, 25));
        splitter_3 = new QSplitter(ajoutEvents);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setGeometry(QRect(30, 160, 242, 26));
        splitter_3->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(splitter_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        splitter_3->addWidget(label_8);
        dateDeb = new QDateEdit(splitter_3);
        dateDeb->setObjectName(QString::fromUtf8("dateDeb"));
        splitter_3->addWidget(dateDeb);
        label_7 = new QLabel(splitter_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        splitter_3->addWidget(label_7);
        dateFin = new QDateEdit(splitter_3);
        dateFin->setObjectName(QString::fromUtf8("dateFin"));
        splitter_3->addWidget(dateFin);
        splitter_4 = new QSplitter(ajoutEvents);
        splitter_4->setObjectName(QString::fromUtf8("splitter_4"));
        splitter_4->setGeometry(QRect(30, 90, 211, 51));
        splitter_4->setOrientation(Qt::Vertical);
        label_9 = new QLabel(splitter_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        splitter_4->addWidget(label_9);
        nom_event = new QLineEdit(splitter_4);
        nom_event->setObjectName(QString::fromUtf8("nom_event"));
        splitter_4->addWidget(nom_event);
        pages->addWidget(ajoutEvents);

        verticalLayout->addWidget(pages);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 337, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        seconnecter->setText(QApplication::translate("MainWindow", "Connection", nullptr));
        sinscrire->setText(QApplication::translate("MainWindow", "Inscription", nullptr));
        titre->setText(QApplication::translate("MainWindow", "Sharecount", nullptr));
        l_Pseudo->setText(QApplication::translate("MainWindow", "Pseudonyme :", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Mot de passe :", nullptr));
        label->setText(QApplication::translate("MainWindow", "Sharecount", nullptr));
        connecter->setText(QApplication::translate("MainWindow", "Se connecter", nullptr));
        co_err->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "Mot de passe :", nullptr));
        l_Pseudo_2->setText(QApplication::translate("MainWindow", "Pseudonyme :", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Sharecount", nullptr));
        inscrire->setText(QApplication::translate("MainWindow", "Se connecter", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Adresse e-mail :", nullptr));
        in_erreur->setText(QString());
        b_groupes->setText(QApplication::translate("MainWindow", "Mes \303\251v\303\251nements", nullptr));
        b_depenses->setText(QApplication::translate("MainWindow", "Mes d\303\251penses", nullptr));
        ajout_groupe->setText(QApplication::translate("MainWindow", "Ajouter un groupe", nullptr));
        ajout_event->setText(QApplication::translate("MainWindow", "Ajout \303\251v\303\251nement", nullptr));
        participants->setText(QApplication::translate("MainWindow", "Participants", nullptr));
        events->setText(QApplication::translate("MainWindow", "Ev\303\251nements", nullptr));
        cagnotte->setText(QApplication::translate("MainWindow", "Cagnotte", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Nom du nouveau groupe :", nullptr));
        ok_groupes->setText(QApplication::translate("MainWindow", "Valider", nullptr));
        ok_event->setText(QApplication::translate("MainWindow", "Valider", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Du", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\303\240", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Nom de l'\303\251v\303\251nement :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
