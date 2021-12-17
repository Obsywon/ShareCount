#ifndef CAGNOTTE_HPP
#define CAGNOTTE_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class cagnotte;
}

/**
 * @brief Cagnotte (ui)
 * @authors Louis Jacques, Guillaume Vautrin
 * @version v16
 */
class cagnotte : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Cagnotte (ui)
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v16
     */
    explicit cagnotte(Model* m, QWidget *parent = nullptr);
    ~cagnotte();

    /**
     * @brief identifie le groupe
     * @param id identifiant
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v16
     */
    void setGroupeId(const int& id);

    /**
     * @brief Met à jour l'historique des transferts
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v16
     */
    void updateHistorique();

signals:
    /**
     * @brief Demande l'affichage des participants
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v16
     */
    void vueComptes();
    /**
     * @brief Demande l'affichage des groupes
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v16
     */
    void vueGroupes();
    /**
     * @brief Demande l'affichage des transferts
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v16
     */
    void vueTransfert();
    /**
     * @brief Demande l'affichage des événements
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v16
     */
    void vueEvent();

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
    Model* m_model;
    int m_id;

};

#endif // CAGNOTTE_HPP
