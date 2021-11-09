cmake_minimum_required(VERSION 3.20)
project(ShareCount)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        REQUIRED)

add_executable(ShareCount main.cpp Utilisateur.cpp Utilisateur.hpp Model.cpp Model.hpp)

target_link_libraries(ShareCount
        Qt5::Core
        )


add_executable(tests tests/tests.cpp Utilisateur.cpp Utilisateur.hpp Model.cpp Model.hpp)
