#ifndef TRANSFERT_HPP
#define TRANSFERT_HPP

#include <QWidget>
#include "Model.hpp"

namespace Ui {
class transfert;
}

class transfert : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief Interface de génération de transferts pour cagnotte
     * @param m model
     * @param parent
     * @author Guillaume VAUTRIN
     * @version v16
     */
    explicit transfert(Model* m, QWidget *parent = nullptr);
    ~transfert();


    /**
     * @brief Définis le groupe auquel toute action sera rattachée
     * @param id identifiant du groupe
     * @author Guillaume Vautrin
     * @version v16
     */
    void setGroupeId(const int& id);

signals:
    /**
     * @brief Demande le retour à l'affichage de la cagnotte
     * @author Guillaume Vautrin
     * @version v16
     */
    void vueCagnotte();

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
    Model* m_model;
    int m_id;
};

#endif // TRANSFERT_HPP
