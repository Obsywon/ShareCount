#ifndef INVITER_HPP
#define INVITER_HPP

#include "Page.hpp"

namespace Ui {
class inviter;
}

/**
 * @brief demande l'invitation d'un individu au groupe
 * @author Guillaume Vautrin
 * @version v17 - ajustement héritage
 */
class inviter : public Page
{
    Q_OBJECT

public:
    /**
     * @brief demande l'invitation d'un individu au groupe
     * @param m model
     * @param fenêtre parente
     * @author Guillaume Vautrin
     * @version v17 - ajustement héritage
     */
    explicit inviter(Model* m, QWidget *parent = nullptr);

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



private:
    Ui::inviter *ui;
};

#endif // INVITER_HPP
