#ifndef CONNECT_HPP
#define CONNECT_HPP

#include "Page.hpp"

namespace Ui {
class Connect;
}

/**
 * @brief Classe contenant l'interface permettant la connection d'un utilisateur
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
class Connect : public Page
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de l'interface de connexion
     * @param m Modèle de données
     * @param parent Widget de fenêtre principale
     * @author Guillaume Vautrin
     * @version v17 - ajustement héritage
     */
    explicit Connect(Model* m, QWidget *parent = nullptr);
    ~Connect();

private:
    Ui::Connect *ui;


private slots:
/**
 * @brief Récepteur de signal : déclenche la validation de connection
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
    void on_connecter_clicked();

/**
* @brief Passe à l'écran d'inscription en vidant les champs locaux au préalable
* @author Guillaume Vautrin
* @version v9 (Dernière modification)
*/
    void on_inscrire_clicked();
};

#endif // CONNECT_HPP
