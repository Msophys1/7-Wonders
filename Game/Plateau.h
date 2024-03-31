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
    Agriculture,
    Architecture,
    Economie,
    Loi,
    Maconnerie,
    Mathematiques,
    Philosophie,
    Strategie,
    Theologie,
    Urbanisme


};

enum class SymboleScientifiques{
    Roue,
    Compas,
    Mortier_Pilon,
    Tablette,
    Lyre,
    Mesure,
    Telescope
};

class Plateau {
public :
    Plateau();

    void setUpPlateau();

    void moveConflictPawn( int boucliers);

    [[nodiscard]] bool checkMilitaryVictory() const;

    [[maybe_unused]] void displayStatePlateau() const;

    [[maybe_unused]] void avancementMilitaire(Joueur& joueur, int steps);

    [[maybe_unused]] void acheterJetonProgres(Joueur& joueur, JetonsProgres token);

    [[maybe_unused]] void collecterSymboleScientifique(Joueur& joueur, SymboleScientifiques symbole);


private :
    // Assuming a simple representation of the military track as an integer
    int militaryTrackPosition{}; // de -9 à 9

    int positionPionConflit;

    // Track the progress tokens available in the game
    std::vector<JetonsProgres> availableJetonsProgres{};

    // A vector of vectors to represent the card layout for each age
    std::vector<std::vector<Cards>> ageCardLayouts{};

    // attribute for scientific track
    std::map<SymboleScientifiques, int> scientificSymbolsCount{};

};


#endif //INC_7_WONDERS_PLATEAU_H
