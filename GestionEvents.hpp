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
     * @brief Affiche les evenements d'un groupe
     * @authors Louis Jacques
     * @version v9 (Dernière modification)
     */
    void afficherEvent(Model* m);

private slots:
/**
 * @brief Réaction à un clique pour ajouter un événement :
 * Déclenche l'envoi d'un signal vers la fenêtre principale 
 * pour afficher l'écran d'ajout d'événement
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
    void on_ajout_event_clicked();

signals:
/**
 * @brief Signal permettant de changer de fenêtre
 * Passage à l'ajout d'un événement
 */
    void addEvent();

private:
    Ui::GestionEvents *ui;
    Model* m_model;
};

#endif // GESTIONEVENTS_HPP
