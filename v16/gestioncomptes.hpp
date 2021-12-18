#ifndef GESTIONCOMPTES_HPP
#define GESTIONCOMPTES_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class gestionComptes;
}

class gestionComptes : public QWidget
{
    Q_OBJECT

public:
    explicit gestionComptes(Model* m, QWidget *parent = nullptr);
    ~gestionComptes();

    /**
     * @brief Affiche les participants d'un groupe
     * @param m model
     * @authors Louis Jacques
     * @version v12 (Dernière modification)
     */
    void afficherComptes(Model* m);


    /**
     * @brief set l'ID d'un groupe
     * @param id identifiant du groupe
     * @authors Louis Jacques
     * @version v12 (Dernière modification)
     */
    void setIDGroupe(const int& id);


private slots:
    /**
     * Permet l'acces aux evenements
     * @author Louis Jacques
     * @version v12 (Ajout)
     */
    void on_events_4_clicked();

    /**
     * Permet le retour aux groupes groupe
     * @author Louis Jacques
     * @version v12 (Ajout)
     */
    void on_retour_groupes_clicked();

    /**
     * @brief demande l'invitation et retourne à fenetre événement si possible
     * @author Guillaume Vautrin
     * @version v15 (Dernière modification)
     */
    void on_inviter_clicked();

    /**
     * @brief Demande la page cagnotte
     * @author Guillaume Vautrin
     * @version v16 (Dernière modification)
     */
    void on_cagnotte_4_clicked();

signals:
    /**
     * @brief Signal permettant de changer de fenêtre
     * @author Louis Jacques
     * @version v15 (Dernière modification) retire id groupe des paramètres
     * Passage à la fenêtre des evenements liée à un groupe
     */
    void vueEvent();

    /**
     * @brief Signal permettant de changer de fenêtre
     * @author Louis Jacques
     * @version v12 (Ajout)
     */
    void vueGroupe();

    /**
     * @brief demande l'invitation et retourne à fenetre événement si possible
     * @author Guillaume Vautrin
     * @version v15 (Dernière modification)
     */
    void vueInvit();

    /**
     * @brief Demande la page cagnotte
     * @author Guillaume Vautrin
     * @version v16 (Dernière modification)
     */
    void vueCagnotte();

private:
    Ui::gestionComptes *ui;
    Model* m_model;
    int m_groupeID;
};

#endif // GESTIONCOMPTES_HPP
