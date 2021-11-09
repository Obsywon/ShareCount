//
// Created by guy on 09/11/2021.
//

#include "../Model.hpp"

int main(int argc, char *argv[]) {
    Model model = Model();
    model.inscrireUtilisateur("pseudo", "email@email.com", "test01");
    std::cout << (model.userToString());


exit (EXIT_SUCCESS);
}
