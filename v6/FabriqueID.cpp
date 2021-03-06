#include "FabriqueID.hpp"
#include <string>

FabriqueID* FabriqueID::f_instance = 0;

FabriqueID* FabriqueID::getInstance(){
    if(!f_instance){
        f_instance = new FabriqueID;
    }
    return f_instance;
}

std::string FabriqueID::getId() {
    counterId++;
    return std::to_string(counterId);
}
