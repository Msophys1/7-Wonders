//
// Created by Mattéo on 26/03/2024.
//


#include "Plateau.h"
#include <iostream>

Plateau::Plateau() : militaryTrackPosition(0) {
    // Initialiser le plateau avec les paramètres par défaut
    setUpPlateau();
}

void Plateau::setUpPlateau() {
    // Configurer l'état initial du Plateau, y compris la position de la voie militaire,
    // les jetons de progrès disponibles et la disposition des cartes d'âge
}

[[maybe_unused]] void Plateau::displayStatePlateau() const {
    // Facultatif : Affiche l'état actuel du Plateau, y compris la piste militaire,
    // les jetons de progrès disponibles et la disposition des cartes d'âge pour une UI basée sur la console.
    std::cout << "Military Track Position: " << militaryTrackPosition << std::endl;
    // Display autres states
}

[[maybe_unused]] void Plateau::advanceMilitaryTrack(Joueur& joueur, int steps) {
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

[[maybe_unused]] bool Plateau::checkVictoireMilitaire() const {
    // basic = 10 à modifier plus tard
    return militaryTrackPosition <= -10 || militaryTrackPosition >= 10;
}

[[maybe_unused]] bool Plateau::checkVictoireScientifique(const Joueur& joueur) {
    // Check if the player has collected 6 different scientific symbols for an instant win
    // This requires tracking which symbols the player has collected
    return Joueur::getUniqueScientificSymbolsCount() >= 6;
}