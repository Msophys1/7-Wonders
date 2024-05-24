#include "Joueur.h"

// Ajouter une ressource au joueur
void Joueur::ajouterRessource(const Ressources& ressource) {
    if (nombreRessources < 100) {
        ressourcesObtenus[nombreRessources] = ressource;
        nombreRessources++;
    } else {
        // Gérer le cas où le tableau est plein
        throw "Le joueur a atteint la limite de ressources.";
    }
}

// Ajouter un symbole scientifique au joueur
void Joueur::ajouterSymboleScientifique(const SymboleScientifiques& symbole) {
    if (nombreSymbolesScientifiques < 7) {
        symbolesScientifiquesObtenus[nombreSymbolesScientifiques] = symbole;
        nombreSymbolesScientifiques++;
    } else {
        // Gérer le cas où le tableau est plein
        throw "Le joueur a atteint la limite de symboles scientifiques.";
    }
}

// Ajouter un jeton de progrès au joueur
void Joueur::ajouterJetonsProgres(const JetonsProgres& jeton) {
    if (nombres_jetons_progres < 10) {
        jetonsPogresObtenus[nombres_jetons_progres] = jeton;
        nombres_jetons_progres++;
    } else {
        // Gérer le cas où le tableau est plein
        throw "Le joueur a atteint la limite de jetons de progrès.";
    }
}
