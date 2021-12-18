#ifndef AJOUTEVENT_HPP
#define AJOUTEVENT_HPP

#include "Page.hpp"

namespace Ui {
class AjoutEvent;
}

/**
 * @brief Structure de données initialisant l'interface permettant de configurer un événement 
 * à ajouter à un groupe 
 * @author Guillaume Vautrin
 * @version v17 (Dernière modification) Ajustement héritage
 */
class AjoutEvent : public Page
{
    Q_OBJECT

public:
    /**
     * @brief Action permettant de retourner à l'écran des groupes
     * @author Guillaume Vautrin
     * @version v17 (Dernière modification) Ajustement héritage
     */
    explicit AjoutEvent(Model* m, QWidget *parent = nullptr);
    ~AjoutEvent();


private slots:
    /**
     * @brief Réaction au bouton de validation : 
     * Déclenche l'ajout d'un événement dans le modèle
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void on_ok_event_clicked();

    /**
     * @brief Annule l'ajout
     * @author Guillaume Vautrin
     * @version v15 (Dernière modification)
     */
    void on_annuler_clicked();

private:
    Ui::AjoutEvent *ui;

    /**
     * @brief Remet à zéro les champs
     * @author Guillaume Vautrin
     * @version v9 (Dernière modification)
     */
    void reset();
};

#endif // AJOUTEVENT_HPP
