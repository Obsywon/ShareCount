#ifndef GESTIONCOMPTES_HPP
#define GESTIONCOMPTES_HPP

#include "Page.hpp"

namespace Ui {
class gestionComptes;
}

class gestionComptes : public Page
{
    Q_OBJECT

public:
    explicit gestionComptes(Model* m, QWidget *parent = nullptr);
    ~gestionComptes();

    /**
     * @brief Affiche les participants d'un groupe
     * @param m model
     * @authors Louis Jacques
     * @version v17 (Dernière modification)
     */
    void update() override;


private slots:
    /**
     * Permet l'acces aux evenements
     * @author Louis Jacques
     * @version v12 (Ajout)
     */
    void on_events_4_clicked();

    /**
     * Permet le retour aux groupes groupe
     * @author Louis Jacques
     * @version v12 (Ajout)
     */
    void on_retour_groupes_clicked();

    /**
     * @brief demande l'invitation et retourne à fenetre événement si possible
     * @author Guillaume Vautrin
     * @version v15 (Dernière modification)
     */
    void on_inviter_clicked();

    /**
     * @brief Demande la page cagnotte
     * @author Guillaume Vautrin
     * @version v16 (Dernière modification)
     */
    void on_cagnotte_4_clicked();

private:
    Ui::gestionComptes *ui;
};

#endif // GESTIONCOMPTES_HPP
