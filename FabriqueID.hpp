#ifndef FABRIQUEID_H
#define FABRIQUEID_H
#include <string>

class FabriqueID
{

public:
    static FabriqueID* getInstance();
    std::string getId();

private :
    FabriqueID(){};
    FabriqueID(FabriqueID const&);
    FabriqueID& operator=(FabriqueID const&);
    static FabriqueID* f_instance;
    int counterId = 0;

};


#endif // FABRIQUEID_H