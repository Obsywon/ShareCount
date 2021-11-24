#ifndef CONNECT_HPP
#define CONNECT_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class Connect;
}

/**
 * @brief Classe contenant l'interface permettant la connection d'un utilisateur
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
class Connect : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructeur de l'interface de connexion
     * @param m Modèle de données
     * @param parent Widget de fenêtre principale
     * @author Guillaume Vautrin
     * @version v8 (Dernière modification)
     */
    explicit Connect(Model* m, QWidget *parent = nullptr);
    ~Connect();

private:
    Ui::Connect *ui;
    Model* m_model;

signals:
/**
 * @brief Signal envoyant vers l'interface des groupes
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
    void groupes();
private slots:
/**
 * @brief Récepteur de signal : déclenche la validation de connection
 * @author Guillaume Vautrin
 * @version v8 (Dernière modification)
 */
    void on_connecter_clicked();
};

#endif // CONNECT_HPP
