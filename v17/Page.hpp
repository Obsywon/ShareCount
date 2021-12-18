#ifndef PAGE_HPP
#define PAGE_HPP

#include <QWidget>
#include "Model.hpp"


/**
 * @brief Classe mère rassemblant les points communs entre les différentes interfaces (et signaux)
 * @author Guillaume Vautrin
 * @version v17
 */
class Page : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Classe mère rassemblant les points communs entre les différentes interfaces (et signaux)
     * @param m model
     * @param parent
     * @author Guillaume Vautrin
     * @version v17
     */
    explicit Page(Model* m, QWidget *parent = nullptr);

    /**
     * @brief set l'ID d'un groupe
     * @param id identifiant du groupe
     * @author Guillaume Vautrin
     * @version v17
     */
    void setIDGroupe(const int& id);

    /**
     * @brief Met à jour le contenu des interfaces si nécessaire
     * @param id identifiant du groupe
     * @author Guillaume Vautrin
     * @version v17
     */
    virtual void update();

signals:
    /**
     * @brief Signal permettant de changer de fenêtre
     * @author Louis Jacques
     * @version v17 (Dernière modification)
     */
    void vueEvent();

    /**
     * @brief Signal permettant de changer de fenêtre
     * @param identifiant du groupe
     * @author Louis Jacques
     * @version v17 (Dernière modification)
     */
    void vueEvent(int id);

    /**
     * @brief Signal permettant de changer de fenêtre
     * @author Louis Jacques
     * @version v17
     */
    void vueGroupe();

    /**
     * @brief demande l'invitation et retourne à fenetre événement si possible
     * @author Guillaume Vautrin
     * @version v17 (Dernière modification)
     */
    void vueInvit();

    /**
     * @brief Signal permettant de changer de fenêtre
     * Passage à la fenêtre des comptes liée à un groupe
     * @author Guillaume Vautrin
     * @version v17 (Dernière modification)
     */
    void vueCompte();

    /**
     * @brief Demande la page cagnotte
     * @author Guillaume Vautrin
     * @version v17 (Dernière modification)
     */
    void vueCagnotte();

    /**
     * @brief Demande l'affichage des transferts
     * @authors Louis Jacques, Guillaume Vautrin
     * @version v17
     */
    void vueTransfert();


    /**
     * @brief Signal permettant de changer de fenêtre
     * Passage à la fenêtre des événements d'un ajout d'événements
     * @version v17 (Dernière modification) retire id groupe des paramètres
     */
     void addEvent();

     /**
      * @brief Signale à la fenêtre principale d'afficher l'interface
      * d'ajout de groupe
      * @author Guillaume Vautrin
      * @version v17 (Dernière modification)
      */
      void ajoutGroupe();

      /**
       * @brief Signal envoyant vers l'interface d'inscription
       * @author Guillaume Vautrin
       * @version v17 (Dernière modification)
       */
      void inscrire();

      /**
      * @brief Signale demandant l'affichage de l'écran de connection
      * @author Guillaume Vautrin
      * @version v17 (Dernière modification)
      */
      void connecter();

      /**
       * @brief demande l'annulation
       * @author Guillaume Vautrin
       * @version v17 (Dernière modification)
       */
      void annuler();

protected :
  /**
   * @brief Model
   * @author Guillaume Vautrin
   * @version v17 (Dernière modification)
   */
    Model* m_model;

    /**
     * @brief Identifiant du groupe
     * @author Guillaume Vautrin
     * @version v17 (Dernière modification)
     */
    int m_groupeID;

};

#endif // PAGE_HPP
