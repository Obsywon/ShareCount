#ifndef AJOUTEVENT_HPP
#define AJOUTEVENT_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class AjoutEvent;
}

/**
 * @brief Structure de données initialisant l'interface permettant de configurer un événement 
 * à ajouter à un groupe 
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
class AjoutEvent : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Action permettant de retourner à l'écran des groupes
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    explicit AjoutEvent(Model* m, QWidget *parent = nullptr);
    ~AjoutEvent();
signals:
    /**
     * @brief Signal envoyé à la fenêtre principale
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void groupes();

private slots:
    /**
     * @brief Réaction au bouton de validation : 
     * Déclenche l'ajout d'un événement dans le modèle
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void on_ok_event_clicked();

private:
    Ui::AjoutEvent *ui;
    Model* m_model{};
};

#endif // AJOUTEVENT_HPP
