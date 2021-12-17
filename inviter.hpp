#ifndef INVITER_HPP
#define INVITER_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class inviter;
}

/**
 * @brief demande l'invitation d'un individu au groupe
 * @author Guillaume Vautrin
 * @version v15 (Dernière modification)
 */
class inviter : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief demande l'invitation d'un individu au groupe
     * @param m model
     * @param fenêtre parente
     * @author Guillaume Vautrin
     * @version v15 (Dernière modification)
     */
    explicit inviter(Model* m, QWidget *parent = nullptr);

    /**
     * @brief attribue l'identifiant du groupe à modifier
     * @param id du groupe
     * @author Guillaume Vautrin
     * @version v15
     */
    void setGroupe(int id);
    ~inviter();

private slots:
    /**
     * @brief demande l'annulation
     * @author Guillaume Vautrin
     * @version v15 (Dernière modification)
     */
    void on_annuler_clicked();

    /**
     * @brief demande l'invitation d'un individu au groupe
     * @author Guillaume Vautrin
     * @version v15 (Dernière modification)
     */
    void on_ok_clicked();

signals:
    /**
     * @brief demande l'annulation
     * @author Guillaume Vautrin
     * @version v15 (Dernière modification)
     */
    void annuler();

    /**
     * @brief demande le passage à l'interface des comptes connus
     * @author Guillaume Vautrin
     * @version v15 (Dernière modification)
     */
    void comptes();

private:
    Ui::inviter *ui;
    Model* m_model;
    int id_groupe;
};

#endif // INVITER_HPP
