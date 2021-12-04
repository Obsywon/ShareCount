#ifndef FABRIQUEID_H
#define FABRIQUEID_H
#include <string>

/**
 * @brief Classe permettant de générer des identifiants
 * @author David Borgondo
 * @version v6 (Dernière modification)
 * @return FabriqueID* 
 */
class FabriqueID
{

public:
    static FabriqueID* getInstance();

    /**
     * Récupère un identifiant unique
     * @return string
     */
    std::string getId();

private :
    FabriqueID(){};

    /**
     * Fabrique d'identifiants
     * @version v6 (Dernière modification)
     * @return FabriqueID* 
     */
    FabriqueID(FabriqueID const&);
    FabriqueID& operator=(FabriqueID const&);
    static FabriqueID* f_instance;
    int counterId = 0; // Conmpteur s'incrémentant à chaque appel

};


#endif // FABRIQUEID_H