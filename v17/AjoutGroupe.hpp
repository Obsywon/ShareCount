#ifndef AJOUTGROUPE_HPP
#define AJOUTGROUPE_HPP

#include "Page.hpp"

namespace Ui {
class AjoutGroupe;
}
/**
 * @brief Structure de données initialisant l'interface permettant d'ajouter un groupe 
 * au modèle
 * @author Guillaume Vautrin
 * @version v17 (Dernière modification) Ajustement héritage
 */
class AjoutGroupe : public Page
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de l'interface d'ajout de groupe
     * 
     * @param m Modèle de données
     * @param parent Widget - fenêtre principal ici
     * @author Guillaume Vautrin
     * @version v17 (Dernière modification) Ajustement héritage
     */
    explicit AjoutGroupe(Model* m, QWidget *parent = nullptr);
    ~AjoutGroupe();

private slots:
    /**
     * @brief Récepteur d'un signal du bouton confirmant l'ajout d'un groupe
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void on_ok_clicked();

    /**
    * @brief déclenche l'annulation et le retour vers la gestion des groupes
    * @authors Guillaume Vautrin
    * @version v9 (Dernière modification)
    */
    void on_annuler_clicked();


private:
    Ui::AjoutGroupe *ui;
};

#endif // AJOUTGROUPE_HPP
