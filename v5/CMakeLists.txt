cmake_minimum_required(VERSION 3.20)
project(ShareCount)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(ShareCount main.cpp Utilisateur.cpp Utilisateur.hpp Model.cpp Model.hpp GestionnaireGroupes.cpp GestionnaireGroupes.hpp Groupe.cpp Groupe.hpp Evenement.cpp Evenement.hpp GestionnaireEvenement.cpp GestionnaireEvenement.hpp GestionnaireComptes.hpp GestionnaireComptes.cpp)

target_link_libraries(ShareCount
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )


add_executable(tests tests/tests.cpp Utilisateur.cpp Utilisateur.hpp Model.cpp Model.hpp GestionnaireGroupes.cpp GestionnaireGroupes.hpp Groupe.cpp Groupe.hpp Evenement.cpp Evenement.hpp GestionnaireEvenement.cpp GestionnaireEvenement.hpp GestionnaireComptes.hpp GestionnaireComptes.cpp)
