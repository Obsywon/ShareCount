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
    void on_ajout_event_clicked();
signals:
    void addEvent(int id);

private:
    Ui::gestionComptes *ui;
    Model* m_model;
    int m_groupeID;
};

#endif // GESTIONCOMPTES_HPP
