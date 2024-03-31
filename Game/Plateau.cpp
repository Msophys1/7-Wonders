//
// Created by Mattéo on 26/03/2024.
//


#include "Plateau.h"
#include <iostream>

Plateau::Plateau() : positionPionConflit(0) {
    // Initialiser le plateau avec les paramètres par défaut
    setUpPlateau();
}

void Plateau::setUpPlateau() {
    // Configurer l'état initial du Plateau, y compris la position de la voie militaire,
    // les jetons de progrès disponibles et la disposition des cartes d'âge
}

void Plateau::moveConflictPawn(int boucliers) {
    positionPionConflit += (boucliers);

    if (positionPionConflit > 9){
        positionPionConflit = 9;
    }
    else if (positionPionConflit <-9){
        positionPionConflit = -9;
    }
}

bool Plateau::checkMilitaryVictory() const {
    return positionPionConflit == 9 || positionPionConflit == -9;
}
[[maybe_unused]] void Plateau::displayStatePlateau() const {
    // Facultatif : Affiche l'état actuel du Plateau, y compris la piste militaire,
    // les jetons de progrès disponibles et la disposition des cartes d'âge pour une UI basée sur la console.
    std::cout << "Military Track Position: " << militaryTrackPosition << std::endl;
    // Display autres states
}

[[maybe_unused]] void Plateau::avancementMilitaire(Joueur& joueur, int steps) {
    // Avancer ou reculer sur la piste militaire en fonction des actions et des étapes du joueur
    // Logique supplémentaire pour gérer l'atteinte de la fin de la piste ou de jalons spécifiques
}

[[maybe_unused]] void Plateau::acheterJetonProgres(Joueur& joueur, JetonsProgres token) {
    // Logique permettant à un joueur d'acquérir un jeton de progression et d'appliquer son effet
    // implique de pouvoir retirer le jeton de la réserve disponible
}

[[maybe_unused]] void Plateau::collecterSymboleScientifique(Joueur& joueur, SymboleScientifiques symbole) {
    // Mise à jour du nombre de symboles scientifiques pour le joueur
    // Vérifier  condition de victoire scientifique
}