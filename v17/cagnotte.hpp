#ifndef CAGNOTTE_HPP
#define CAGNOTTE_HPP

#include "Page.hpp"

namespace Ui {
class cagnotte;
}

/**
 * @brief Cagnotte (ui)
 * @authors Louis Jacques, Guillaume Vautrin
 * @version v16
 */
class cagnotte : public Page
{
    Q_OBJECT

public:
    /**
     * @brief Gestion de la cagnotte (interface)
     * @param m Model
     * @param parent
     * @author Guillaume Vautrin
     * @version v17 - ajustement héritage
     */
    explicit cagnotte(Model* m, QWidget *parent = nullptr);
    ~cagnotte();

    /**
     * @brief Met à jour l'historique des transferts
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v17 - ajustement héritage
     */
    void update() override;

signals:


private slots:
    /**
     * @brief Demande l'affichage des événements
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v16
     */
    void on_events_clicked();
    /**
     * @brief Demande l'affichage des participants
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v16
     */
    void on_participants_clicked();
    /**
     * @brief Demande l'affichage des groupes
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v16
     */
    void on_retour_groupes_clicked();
    /**
     * @brief Demande l'affichage des transferts
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v16
     */
    void on_ajout_transfert_clicked();

private:
    Ui::cagnotte *ui;
};

#endif // CAGNOTTE_HPP
