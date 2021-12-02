#include "Model.hpp"

/**
 * Créer le modèle, classe facade, et initialise la base de données
* @authors Guillaume Vautrin
* @version v9 (Dernière modification): initialisation de la base de données
*/
Model::Model(){
    m_db.initialisation();
}

/**
* Permet de vérifier la validité du mot de passe
* @param mdp string
* @return bool
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)  : const ajouté
*/
bool Model::estValideMdP(const std::string& mdp) {
    bool test = true;
    if (!mdp.empty()){
        for (char i : mdp){
            if (std::isblank(i)){
                test = false;
            }
        }
    }
    return test;
}

/**
* Vérifie si l'e-mail entrée est valide
* @param email string
* @return bool
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)  : const ajouté
*/
bool Model::estValideEmail(const std::string& email) {
    const std::regex pattern (R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    return std::regex_match(email, pattern);
}

/**
* Inscrire un utilisateur
* @param pseudo pseudo
* @param email email
* @param mdp mdp
* @return bool true si utilisateur est bien inscris
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v9 (Dernière modification)  : const ajouté + ajout inscription à base de données
*/
bool Model::inscrireUtilisateur(const std::string& pseudo, const std::string& email, const std::string& mdp) {
    // Vérifie l'existence d'un utilisateur dans la base de données
    bool existe = m_db.existeUtilisateur(email, pseudo, mdp);

    // Si l'utilisateur n'existe pas, on le crée
    if (!existe){
        int id_user;

        // Ajout l'utilisateur dans la base de données & récupère son id
        id_user = m_db.ajouterUtilisateur(pseudo, email, mdp);
        if (m_groupes.taille() > 0){
            m_groupes = GestionnaireGroupes();
        }
        // Crée localement l'utilisateur
        m_user = Utilisateur(id_user, pseudo, email, mdp, &m_groupes);
    }
    return existe;
}

/**
* Vérifie si un utilisateur existe bien dans la base de données
* @param pseudo string
* @param mdp string
* @return bool
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)  : const ajouté
*/
bool Model::compteExiste(const std::string &pseudo, const std::string &mdp) {
    return m_db.existeUtilisateur("", pseudo, mdp);
}

/**
* Connecte et charge le compte utilisateur indiqué si il existe
* @param pseudo string
* @param email string
* @param mdp string
* @return boolean
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v9 (Dernière modification)  : ajout connection à base de données
*/
bool Model::connecterUtilisateur(const std::string& pseudo, const std::string& email, const std::string& mdp) {
    bool existe = false;
    if (m_db.existeUtilisateur(email, pseudo, mdp)){
        int id = 0;
        if (m_groupes.taille() > 0){
            m_groupes = GestionnaireGroupes();
        }
        id = m_db.getUserID(pseudo, mdp);
        m_user = Utilisateur(id, pseudo, email, mdp, &m_groupes);
        existe = true;
    }
    return existe;
}

/**
* Détaille les informations connus (sans le mdp) de l'utilisateur local
* @return string
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)  : const ajouté
*/
std::string Model::userToString() const{
    return m_user.toString();
}

/**
* Détaille les groupes auxquels l'utilisateur local appartient
* @return string
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)  : const ajouté
*/
std::string Model::groupesToString() const {
    return m_groupes.toString();
}


/**
* Créer un nouveau groupe
* @param nom string nom du groupe
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v9 (dernière modification) : Ajout de fonctionnalité BDD
*/
void Model::creerGroupe(const std::string& nom) {
    int id = m_db.ajouterGroupe(m_user.getId(), nom);
    m_groupes.ajouterGroupe(id, nom);
}

/**
* Créer un événement dans un groupe particulier
* @param IDgroupe string identifiant du groupe visé
* @param nom Nom de l'événement
* @param dateDeb Date de début
* @param dateFin Date de fin
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v9 (Dernière modification)  : type modifé + ajout database
*/
void Model::creerEvenement(const int& IDgroupe, const std::string& nom, const std::string& dateDeb, const std::string& dateFin) {
    int idEvent = m_db.ajouterEvenement(IDgroupe, nom, dateDeb, dateFin);
    m_groupes.ajouterEvenemenent(IDgroupe, idEvent, nom, dateDeb, dateFin);
}


/**
* Ajoute un utilisateur à un groupe
* @param idGroupe Identifiant du groupe visé
* @param u Utilisateur à inscrire au groupe
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v9 (Dernière modification)  : type modifé
*/
void Model::ajouterMembreAGroupe(const int& idGroupe, const Utilisateur *u){
    m_groupes.ajoutMembreAGroupe(idGroupe,u);
}

/**
* Détaille toutes les informations connues par le modèle
* @return string
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v8 (Dernière modification)
*/
std::string Model::toString() const{
    std::string temp = userToString();
    temp.append("\n");
    temp.append(m_groupes.toString());
    return temp;
}

/**
* @brief Liste des ids du gstionnaire de groupe
* @return vector
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v9 (Dernière modification)  : type modifé
*/
std::vector <int> Model::listeIDs() const{
    return m_groupes.listeIDs();
}

/**
 * @brief Liste des noms du gstionnaire de groupe
 * @return vector
 * @authors Guillaume Vautrin, Louis Jacques, David Borgondo
 * @version v8 (Dernière modification)  : const ajouté
 */
std::vector <std::string> Model::listeNoms() const{
    return m_groupes.listeNoms();
}

/**
* Récupère tous les groupes connus
* @return Groupes (hashmap)
* @authors Guillaume Vautrin, Louis Jacques, David Borgondo
* @version v9 (Dernière modification)  : type modifé
*/
std::unordered_map<int, Groupe> *Model::getTousLesGroupesConnus() {
    return m_groupes.getTousLesGroupesConnus();
}

/**
 * Récupère l'ensemble des groupes connus
 * @return unordered_map <ID, Groupe>
 * @authors Guillaume Vautrin, Louis Jacques
 * @version v9 (Dernière modification)  : type modifé
 */
std::unordered_map<int, Evenement> * Model::getTousLesEvenementsConnus(int identifiant){
    return m_groupes.getTousLesEvenementsConnus(identifiant);
}

