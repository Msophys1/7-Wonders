cmake_minimum_required(VERSION 3.27)
project(7_Wonders)

set(CMAKE_CXX_STANDARD 17)

add_library(7_Wonders STATIC main.cpp
        Game/GameManager.cpp
        Game/GameManager.h
        Game/Joueur.cpp
        Game/Joueur.h
        Game/Plateau.cpp
        Game/Plateau.h
        Game/Cards.cpp
        Game/Cards.h)
