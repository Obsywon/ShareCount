#ifndef GESTIONEVENTS_HPP
#define GESTIONEVENTS_HPP

#include "Page.hpp"

namespace Ui {
class GestionEvents;
}

/**
 * @brief Lancement de l'application
 * @version v17 - ajustement héritage
 */
class GestionEvents : public Page
{
    Q_OBJECT

public:
    /**
     * @brief Lancement de l'application
     * @param m Model
     * @param parent
     * @version v17 - ajustement héritage
     */
    explicit GestionEvents(Model* m, QWidget *parent = nullptr);
    ~GestionEvents();

    void update() override;

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

    /**
     * @brief Demande la page cagnotte
     * @author Guillaume Vautrin
     * @version v16 (Dernière modification)
     */
    void on_cagnotte_4_clicked();

private:
    Ui::GestionEvents *ui;
};

#endif // GESTIONEVENTS_HPP
