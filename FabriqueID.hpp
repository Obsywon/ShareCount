#ifndef FABRIQUEID_H
#define FABRIQUEID_H
#include <string>

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
     */
    FabriqueID(FabriqueID const&);
    FabriqueID& operator=(FabriqueID const&);
    static FabriqueID* f_instance;
    int counterId = 0;

};


#endif // FABRIQUEID_H