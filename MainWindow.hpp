#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Launch.hpp"
#include "Connect.hpp"
#include "Inscription.hpp"
#include "GestionGroupes.hpp"
#include "GestionEvents.hpp"
#include "AjoutGroupe.hpp"
#include "AjoutEvent.hpp"
#include "gestioncomptes.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Enumération donnant l'indice de chaque interface
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
enum pages {LAUNCH, CONNECT, INSCRIPTION, GROUPES, EVENTS, ADDGROUP, ADDEVENT, COMPTES};

/**
 * @brief Fenêtre principale sur laquelle est instantiée toutes
 * les interfaces. Les interfaces demandent à cette classe pour faire
 * apparaître la suivante.
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Model* m, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    /**
     * @brief Modèle de données
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    Model *m_model;
        /**
     * @brief Interface d'accueil
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    Launch *m_launch;
        /**
     * @brief Interface d'inscription
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    Inscription *m_inscription;
        /**
     * @brief Interface de connexion
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    Connect *m_connection;
        /**
     * @brief Interface de gestions de groupes
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    GestionGroupes* m_groupes;
        /**
     * @brief Interface de gestion d'évenements
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    GestionEvents* m_events;
        /**
     * @brief Interface d'ajout de groupes
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    AjoutGroupe* m_addGroup;
        /**
     * @brief Interface d'ajout d'événements
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    AjoutEvent* m_addEvent;

    /**
     * @brief Interface de gestion de comptes
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    //gestionComptes* m_comptes;

        /**
     * @brief Interface d'ajout de groupes
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void changerPage(int i);

public slots:
    /**
     * @brief Affiche l'inscription
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void afficherInscription();
        /**
     * @brief Affiche la connection
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void afficherConnection();
        /**
     * @brief Affiche les groupes
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void afficherGroupes();
        /**
     * @brief AFfiche l'ajout de groupes
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void afficherAjoutGroupe();
    /**
     * @brief Affiche les événements
     * @param id du groupe auquel appartient l'événement
     * @author Guillaume Vautrin , Louis Jacques
     * @version v9 (Dernière modification)
     */
    void afficherEvenement(int id);

        /**
     * @brief Affiche l'ajout d'événements
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void afficherAjoutEvent(int id);

        /**
     * @brief Affiche les Comptes
     * @author Louis Jacques
     * @version v12 (Dernière modification)
     */
    //void afficherComptes(int id);

};
#endif // MAINWINDOW_H
