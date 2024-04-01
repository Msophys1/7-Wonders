//
// Created by Mattéo on 26/03/2024.
//

#include "Joueur.h"

#include <iostream>
Joueur::Joueur(int idJoueur, std::string nom, Ressources *joueurRessources, JetonsProgres *joueurSymbolesProgres,
               int numRessources, int numSymbolesProgres) :
               id(idJoueur), nom(nom), nombre_ressources(numRessources), nombre_symboles_progres(numSymbolesProgres) {
    // Initialisation des ressources du joueur
    for(int i = 0; i < numRessources; ++i) {
        ressources[i] = joueurRessources[i];
    }


}
