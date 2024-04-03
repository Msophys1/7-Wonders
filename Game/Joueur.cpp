#include "Joueur.h"

// Ajouter une ressource au joueur
void ajouterRessource(const Ressources& ressource) {
    if (nombreRessources < 100) {
        ressourcesObtenus[nombreRessources] = ressource;
        nombreRessources++;
    } else {
        // Gérer le cas où le tableau est plein
        throw "Le joueur a atteint la limite de ressources.";
    }
}

// Ajouter un symbole scientifique au joueur
void ajouterSymboleScientifique(const SymboleScientifiques& symbole) {
    if (nombreSymbolesScientifiques < 7) {
        symbolesScientifiquesObtenus[nombreSymbolesScientifiques] = symbole;
        nombreSymbolesScientifiques++;
    } else {
        // Gérer le cas où le tableau est plein
        throw "Le joueur a atteint la limite de symboles scientifiques.";
    }
}

// Ajouter un jeton de progrès au joueur
void ajouterJetonsProgres(const JetonsProgres& jeton) {
    if (nombres_jetons_progres < 10) {
        jetonsPogresObtenus[nombres_jetons_progres] = jeton;
        nombres_jetons_progres++;
    } else {
        // Gérer le cas où le tableau est plein
        throw "Le joueur a atteint la limite de jetons de progrès.";
    }
}

// Activer effet chainage
void activerEffetChainage(int niveau) {
    switch (niveau) {
        case 1:
            effetChainage.vase = true;
            break;
        case 2:
            effetChainage.masque = true;
            break;
        case 3:
            effetChainage.soleil = true;
            break;
        case 4:
            effetChainage.eau = true;
            break;
        case 5:
            effetChainage.lune = true;
            break;
        case 6:
            effetChainage.sabot = true;
            break;
        case 7:
            effetChainage.epee = true;
            break;
        case 8:
            effetChainage.engrenage = true;
            break;
        case 9:
            effetChainage.livre = true;
            break;
        default:
            // Niveau invalide
            throw "Niveau de chaînage invalide.";
    }
}