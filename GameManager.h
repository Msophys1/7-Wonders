#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

#include "Type.h"
#include "Joueur.h"
#include "Plateau.h"
#include "Carte.h"

using namespace std;

class GameManager {
private:
    vector<Batiment> batiment; // A creer dans initialisation (static ?)
    vector<Merveille> merveilles; // A creer dans initialisation (static ?)
    vector<Guilde> guilde; // A creer dans initialisation (static ?)

    Joueur joueur1;
    Joueur joueur2;
    Plateau plateau;
    vector<JetonsProgres> jetonsProgresDisponibles;
    vector<Carte> defausse;

public:
    // Constructeur
    GameManager(const Joueur& j1, const Joueur& j2) : joueur1(j1), joueur2(j2) {joueur1.setAdversaire(&joueur2), joueur2.setAdversaire(&joueur1);}

    // Accesseurs
    Joueur getJoueur1() const { return joueur1; }
    Joueur getJoueur2() const { return joueur2; }
    Plateau getPlateau() const { return plateau; }

    const vector<Batiment>& getBatiment() const { return batiment; }
    const vector<Merveille>& getMerveilles() const { return merveilles; }
    const vector<Guilde>& getGuilde() const { return guilde; }
    const vector<JetonsProgres>& getJetonsProgresDisponibles() const { return jetonsProgresDisponibles; }
    const vector<Carte>& getDefausse() const { return defausse; }

    // Setteurs
    void ajouterBatiment(const Batiment& b) { batiment.push_back(b); }
    void ajouterMerveille(const Merveille& m) { merveilles.push_back(m); }
    void ajouterGuilde(const Guilde& g) { guilde.push_back(g); }
    void ajouterJetonProgres(const JetonsProgres& jp) { jetonsProgresDisponibles.push_back(jp); }
    void ajouterCarteDefausse(const Carte& c) { defausse.push_back(c); }

    // Méthodes de gestion du jeu
    void initialiserJeu();
    void selectionnerJetonsProgres();
    void choisirMerveilles();
    void commencerPartie();

    // Destructeur
    ~GameManager() = default;
};

#endif // GAMEMANAGER_H
