#ifndef AJOUTGROUPE_HPP
#define AJOUTGROUPE_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class AjoutGroupe;
}
/**
 * @brief Structure de données initialisant l'interface permettant d'ajouter un groupe 
 * au modèle
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
class AjoutGroupe : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de l'interface d'ajout de groupe
     * 
     * @param m Modèle de données
     * @param parent Widget - fenêtre principal ici
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
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

signals:
    /**
     * @brief Signal envoyé à la fenêtre principale
     * Permet de revenir sur la page de groupes
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void groupes();

private:
    Ui::AjoutGroupe *ui;
    Model* m_model;
};

#endif // AJOUTGROUPE_HPP
