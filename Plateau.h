#ifndef INC_7_WONDERS_PLATEAU_H
#define INC_7_WONDERS_PLATEAU_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "Carte.h"
#include "Joueur.h"

class Plateau {
public:
    Plateau();
    // Getteurs
    int getPositionPionConflit() const { return positionPionConflit; }
    bool getSaccage1duJoueur1() const { return saccage1duJoueur1; }
    bool getSaccage2duJoueur1() const { return saccage2duJoueur1; }
    bool getSaccage3duJoueur1() const { return saccage3duJoueur1; }
    bool getSaccage1duJoueur2() const { return saccage1duJoueur2; }
    bool getSaccage2duJoueur2() const { return saccage2duJoueur2; }
    bool getSaccage3duJoueur2() const { return saccage3duJoueur2; }
    const vector<JetonsProgres>& getJetonsProgresPlateau() const { return jetonsProgresPlateau; }

    // Setteurs
    void setPositionPionConflit(int position) { positionPionConflit = position; }
    void setSaccage1duJoueur1(bool saccage) { saccage1duJoueur1 = saccage; }
    void setSaccage2duJoueur1(bool saccage) { saccage2duJoueur1 = saccage; }
    void setSaccage3duJoueur1(bool saccage) { saccage3duJoueur1 = saccage; }
    void setSaccage1duJoueur2(bool saccage) { saccage1duJoueur2 = saccage; }
    void setSaccage2duJoueur2(bool saccage) { saccage2duJoueur2 = saccage; }
    void setSaccage3duJoueur2(bool saccage) { saccage3duJoueur2 = saccage; }
    void setJetonsProgresPlateau(const vector<JetonsProgres>& jetons) { jetonsProgresPlateau = jetons; }

    // Fonction pour choisir au hasard 5 jetons et qui les mets dans jetonsProgresPlateau
    void setJetonsPlateau();

    // operator<< qui montre l'état du plateau


private:
    int positionPionConflit = 0; // de -9 à 9 (9 = victoire pour le joueur 1)
    bool saccage1duJoueur1 = false;
    bool saccage2duJoueur1 = false;
    bool saccage3duJoueur1 = false;
    bool saccage1duJoueur2 = false;
    bool saccage2duJoueur2 = false;
    bool saccage3duJoueur2 = false;
    vector<JetonsProgres> jetonsProgresPlateau;

};

#endif //INC_7_WONDERS_PLATEAU_H
