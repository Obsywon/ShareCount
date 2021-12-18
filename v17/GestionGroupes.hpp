#ifndef GESTIONGROUPES_HPP
#define GESTIONGROUPES_HPP

#include "Page.hpp"
#include <QListWidgetItem>
#include <vector>

namespace Ui {
class GestionGroupes;
}

/**
 * @brief Logique derrière l'interface de gestion de groupes
 * connu d'un compte utilisateur
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v17 (Dernière modification)
 */
class GestionGroupes : public Page
{
    Q_OBJECT

public:
    explicit GestionGroupes(Model* m, QWidget *parent = nullptr);
    ~GestionGroupes();

    /**
     * @brief Affiche les groupes d'un Utilisateur
     * @authors Guillaume Vautrin , Louis Jacques
     * @version v17 (Dernière modification)
     */
    void update() override;

private slots:
    /**
     * @brief Réaction au bouton d'ajout d'un groupe
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void on_ajout_groupe_clicked();
/**
 * @brief Permet d'accéder à la page d'un groupe et d'en afficher les événements
 * @author Guillaume Vautrin
 * @version v9 (Dernière modification)
 */
    void on_groupes_itemClicked(QListWidgetItem *item);


private:
    Ui::GestionGroupes *ui;
    std::vector<int> m_listIDs;
};

#endif // GESTIONGROUPES_HPP
