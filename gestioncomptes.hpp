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
     * @brief Affiche les Comptes d'un Evenement
     * @authors  Louis Jacques
     * @version v12 (Dernière modification)
     */
    void afficherComptes(Model* m);

    /**
     * @brief set l'id de groupe
     * @authors  Louis Jacques
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

signals:
    /**
     * @brief Signal permettant de changer de fenêtre
     * @author Louis Jacques
     * @version v12 (Ajout)
     * Passage à la fenêtre des evenements liée à un groupe
     */
    void vueEvent(int id);

    /**
     * @brief Signal permettant de changer de fenêtre
     * @author Louis Jacques
     * @version v12 (Ajout)
     * Passage à la fenêtre des événements d'un groupe
     */
    void vueGroupe();

private:
    Ui::gestionComptes *ui;
    Model* m_model;
    int m_groupeID;
};

#endif // GESTIONCOMPTES_HPP
