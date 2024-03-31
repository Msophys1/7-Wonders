//
// Created by Mattéo on 26/03/2024.
//

#ifndef INC_7_WONDERS_JOUEUR_H
#define INC_7_WONDERS_JOUEUR_H

#include "Plateau.h"
#include <unordered_set>


class Joueur {
private:
    std::unordered_set<SymboleScientifiques> scientificSymbols;

public:

    bool checkScientificVictory() const;
    static void playMilitaryCard(Plateau& plateau, int boucliers);
};


#endif //INC_7_WONDERS_JOUEUR_H
