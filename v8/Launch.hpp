#ifndef LAUNCH_HPP
#define LAUNCH_HPP

#include <QWidget>
#include "Model.hpp"
#include "Connect.hpp"
#include "Inscription.hpp"

namespace Ui {
class Launch;
}

/**
 * @brief Interface de choix : connexion ou inscription
 * Première interface qui s'affiche
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
class Launch : public QWidget
{
    Q_OBJECT

public:
/**
 * @brief Constructeur de l'interface de lancement d'app
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
 * @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
    explicit Launch(Model* m, QWidget *parent = nullptr);
    ~Launch();

private slots:
/**
 * @brief Récepteur du bouton 's'inscrire'
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
    void on_sinscrire_clicked();

/**
 * @brief Récepteur du bouton 'se connecter
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
    void on_seconnecter_clicked();

signals:
/**
 * @brief Demande l'affichage de l'interface d'inscription
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
    void inscrire();

/**
 * @brief Demande l'affichage de l'interface de connexion
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
*/
    void connecter();

private:
    Ui::Launch *ui;
    Model* m_model;
};

#endif // LAUNCH_HPP
