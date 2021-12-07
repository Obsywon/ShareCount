#include "FabriqueID.hpp"
#include <string>

/**
 * @brief Singleton générant un identifiant unique
 * @author David Borgondo
 * @version v6 (Dernière modification)
 */
FabriqueID* FabriqueID::f_instance = 0;

/**
 * @brief Récupère une instance pour accéder à l'identifiant unique
 * @author David Borgondo
 * @version v6 (Dernière modification)
 * @return FabriqueID* 
 */
FabriqueID* FabriqueID::getInstance(){
    if(!f_instance){
        f_instance = new FabriqueID;
    }
    return f_instance;
}
/**
 * @brief Récupère l'identifiant unique
 * @author David Borgondo
 * @version v6 (Dernière modification)
 * @return std::string
 */
std::string FabriqueID::getId() {
    counterId++;
    return std::to_string(counterId);
}
