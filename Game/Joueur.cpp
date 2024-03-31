//
// Created by Mattéo on 26/03/2024.
//

#include "Joueur.h"
#include "Plateau.h"

bool Joueur::checkScientificVictory() const {
    return scientificSymbols.size() == 6;
}

void Joueur::playMilitaryCard(Plateau &plateau, int boucliers) {
    plateau.moveConflictPawn(boucliers);
    if(plateau.checkMilitaryVictory()){
        // Victoire
    }

}
