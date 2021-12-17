#ifndef INSCRIPTION_HPP
#define INSCRIPTION_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class Inscription;
}
/**
 * @brief Interface permettant l'inscription
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
class Inscription : public QWidget
{
    Q_OBJECT

public:
/**
 * @brief Constructeur de l'interface d'inscription
 * 
 * @param m Modèle de données
 * @param parent Fenêtre principale
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
    explicit Inscription(Model* m, QWidget *parent = nullptr);
    ~Inscription();

private:
    Ui::Inscription *ui;
    Model* m_model;

signals:
/**
 * @brief Signale demandant l'affichage des groupes
* @author Guillaume Vautrin
* @version v8 (Dernière modification)
 */
    void groupes();

/**
* @brief Signale demandant l'affichage de l'écran de connection
* @author Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    void connecter();

private slots:
/**
 * @brief réaction au bouton 'inscription'
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
    void on_inscrire_clicked();

/**
* @brief Passe à l'écran de connexion en vidant les champs locaux au préalable
* @author Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    void on_connecter_clicked();
};

#endif // INSCRIPTION_HPP
