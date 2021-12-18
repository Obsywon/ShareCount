#ifndef LAUNCH_HPP
#define LAUNCH_HPP

#include "Page.hpp"

namespace Ui {
class Launch;
}

/**
 * @brief Lancement de l'application
 * @version v17 - ajustement héritage
 */
class Launch : public Page
{
    Q_OBJECT

public:
/**
 * @brief Constructeur de l'interface de lancement d'app
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
 * @author Guillaume Vautrin
* @version v17 (Dernière modification)
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


private:
    Ui::Launch *ui;
};

#endif // LAUNCH_HPP
