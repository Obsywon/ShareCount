#ifndef GESTIONEVENTS_HPP
#define GESTIONEVENTS_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class GestionEvents;
}

/**
 * @brief Aspect logique derrière l'interface de gestion des 
 * événements liés à un groupe
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
class GestionEvents : public QWidget
{
    Q_OBJECT

public:
    explicit GestionEvents(Model* m, QWidget *parent = nullptr);
    ~GestionEvents();

    /**
 * Attribue l'identifiant d'un groupe
 * @param id identifiant
 * @author Guillaume Vautrin
 * @version v9 (ajout)
 */
    void setIdGroupe(const int& id);

    /**
     * @brief Affiche les evenements d'un groupe
     * @authors Louis Jacques
     * @version v9 (Dernière modification)
     */
    void afficherEvent();

private slots:
/**
 * @brief Réaction à un clique pour ajouter un événement :
 * Déclenche l'envoi d'un signal vers la fenêtre principale 
 * pour afficher l'écran d'ajout d'événement
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
    void on_ajout_event_clicked();
/**
 * Permet le retour aux groupes groupe
 * @author Guillaume Vautrin
 * @version v9 (Ajout)
 */
    void on_retour_groupes_clicked();

    /**
     * Permet l'acces aux participants
     * @author Louis Jacques
     * @version v12 (Ajout)
     */
    void on_participants_4_clicked();

signals:
/**
 * @brief Signal permettant de changer de fenêtre
 * Passage à la fenêtre des événements d'un ajout d'événements
 */
    void addEvent(int id);
/**
 * @brief Signal permettant de changer de fenêtre
 * Passage à la fenêtre des événements d'un groupe
 */
    void groupes();

/**
 * @brief Signal permettant de changer de fenêtre
 * Passage à la fenêtre des comptes liée à un groupe
 */
    void vueCompte(int id);

private:
    Ui::GestionEvents *ui;
    Model* m_model;
    int m_groupeId;
};

#endif // GESTIONEVENTS_HPP
