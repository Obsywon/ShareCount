#ifndef TRANSFERT_HPP
#define TRANSFERT_HPP

#include "Page.hpp"

namespace Ui {
class transfert;
}

/**
 * @brief Interface de génération de transferts pour cagnotte
 * @param m model
 * @param parent
 * @author Guillaume Vautrin
 * @version v17 - ajustement héritage
 */
class transfert : public Page
{
    Q_OBJECT

public:

    /**
     * @brief Interface de génération de transferts pour cagnotte
     * @param m model
     * @param parent
     * @author Guillaume Vautrin
     * @version v17 - ajustement héritage
     */
    explicit transfert(Model* m, QWidget *parent = nullptr);
    ~transfert();

private slots:

    /**
     * @brief Annule le paiement, retour à l'interface
     * @author Guillaume Vautrin
     * @version v16
     */
    void on_annuler_clicked();
    /**
     * @brief Effectue un transfert
     * @author Guillaume Vautrin
     * @version v16
     */
    void on_ok_clicked();

private:
    Ui::transfert *ui;
};

#endif // TRANSFERT_HPP
