//
// Created by Mattéo on 26/03/2024.
//

#ifndef INC_7_WONDERS_PLATEAU_H
#define INC_7_WONDERS_PLATEAU_H

#include <vector>
#include <vector>
#include <map>
#include "Cards.h" // Make sure to include the Card class
#include "Joueur.h"

enum class JetonsProgres{

};

enum class SymboleScientifiques{
    Roue,
    Tablette,
    Compas
};

class Plateau {
public :
    Plateau();

    void setUpPlateau();

    [[maybe_unused]] void displayStatePlateau() const;

    [[maybe_unused]] void advanceMilitaryTrack(Joueur& joueur, int steps);

    [[maybe_unused]] void acheterJetonProgres(Joueur& joueur, JetonsProgres token);

    [[maybe_unused]] void collecterSymboleScientifique(Joueur& joueur, SymboleScientifiques symbole);

    [[maybe_unused]] bool checkVictoireMilitaire() const;

    [[maybe_unused]] static bool checkVictoireScientifique(const Joueur& joueur);

private :
    // Assuming a simple representation of the military track as an integer
    int militaryTrackPosition;

    // Track the progress tokens available in the game
    std::vector<JetonsProgres> availableJetonsProgres{};

    // A vector of vectors to represent the card layout for each age
    std::vector<std::vector<Cards>> ageCardLayouts{};

    // attribute for scientific track
    std::map<SymboleScientifiques, int> scientificSymbolsCount{};

};


#endif //INC_7_WONDERS_PLATEAU_H
