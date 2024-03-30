#include "joueur.h"

// Constructeur
Joueur::Joueur(int idJoueur, Ressources joueurRessources[], Symboles_Progres joueurSymbolesProgres[], int numRessources, int numSymbolesProgres)
        : id(idJoueur), nombre_ressources(numRessources), nombre_symboles_progres(numSymbolesProgres) {
    for (int i = 0; i < numRessources; ++i) {
        ressources[i] = joueurRessources[i];
    }
    for (int i = 0; i < numSymbolesProgres; ++i) {
        symboles_progres[i] = joueurSymbolesProgres[i];
    }
}

// Ajouter ressources
void Joueur::ajouterRessource(Ressources nouvelleRessource) {
    if (nombre_ressources < 30) {
        ressources[nombre_ressources++] = nouvelleRessource;
    } else {
        cerr << "Le joueur a déjà atteint la limite de ressources." << endl;
    }
}

// Ajouter symbole
void Joueur::ajouterSymboleProgres(Symboles_Progres nouveauSymboleProgres) {
    if (nombre_symboles_progres < 7) {
        symboles_progres[nombre_symboles_progres++] = nouveauSymboleProgres;
    } else {
        cerr << "Le joueur a déjà atteint la limite de symboles de progrès." << endl;
    }
}
