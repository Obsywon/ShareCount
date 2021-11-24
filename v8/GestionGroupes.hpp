#ifndef GESTIONGROUPES_HPP
#define GESTIONGROUPES_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class GestionGroupes;
}

/**
 * @brief Logique derrière l'interface de gestion de groupes
 * connu d'un compte utilisateur
 * @authors Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
class GestionGroupes : public QWidget
{
    Q_OBJECT

public:
    explicit GestionGroupes(Model* m, QWidget *parent = nullptr);
    ~GestionGroupes();

private slots:
    /**
     * @brief Réaction au bouton d'ajout d'un groupe
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void on_ajout_groupe_clicked();

    /**
     * @brief Réaction au bouton pour créer un événement
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    void on_b_groupes_clicked();

signals:
/**
 * @brief Signale à la fenêtre principale d'afficher l'interface
 * d'ajout de groupe
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
    void ajoutGroupe();
/**
 * @brief Signale à la fenêtre principale d'afficher l'interface
 * d'un événement sélectionné par l'utilisateur
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
    void evenement();

private:
    Ui::GestionGroupes *ui;
    Model* m_model;
};

#endif // GESTIONGROUPES_HPP
