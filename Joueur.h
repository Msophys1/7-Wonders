#include <iostream>
#include <string>
#include <map>
#include "Type.h"
#include "Carte.h"
using namespace std;

class Joueur {
private:
    string nom;
    vector<Batiment> batiments;
    vector<Merveille> merveilles;
    vector<Guilde> guilde;
    vector<JetonsProgres> jetonsProgres;
    Joueur *adversaire;

    bool effetRejouer = false; // Indique si le joueur peut rejouer (effet de Theologie).
    int pointsDeVictoire = 0;
    int pieces = 7;
    int puissanceMilitaire = 0;

public:
    // Constructeur
    Joueur(string nom) : nom(nom) {}

    // Destructeur
    ~Joueur() = default;

    // Setters
    void setNom(string nouveauNom) { nom = nouveauNom; }
    void setEffetRejouer(bool nouvelEffet) { effetRejouer = nouvelEffet; }
    void setPointsDeVictoire(int nouveauxPoints) { pointsDeVictoire = nouveauxPoints; }
    void setPieces(int nouvellesPieces) { pieces = nouvellesPieces; }
    void setPuissanceMilitaire(int nouvellePuissance) { puissanceMilitaire = nouvellePuissance; }
    void setAdversaire(Joueur* nouvelAdversaire) { adversaire = nouvelAdversaire; }
    void setBatiment(const vector<Batiment>& nouvellesCartes) { batiments = nouvellesCartes; }
    void setMerveilles(const vector<Merveille>& nouvellesMerveilles) { merveilles = nouvellesMerveilles; }
    void setJetonsProgres(const vector<JetonsProgres>& nouveauxJetons) { jetonsProgres = nouveauxJetons; }

    // Getters
    const string& getNom() const { return nom; }
    bool getEffetRejouer() const { return effetRejouer; }
    int getPointsDeVictoire() const { return pointsDeVictoire; }
    int getPieces() const { return pieces; }
    int getPuissanceMilitaire() const { return puissanceMilitaire; }
    Joueur* getAdversaire() const { return adversaire; }
    const vector<Batiment>& getBatiment() const { return batiments; }
    const vector<Merveille>& getMerveilles() const { return merveilles; }
    const vector<JetonsProgres>& getJetonsProgres() const { return jetonsProgres; }

    // Ajouter une merveille au joueur
    void ajouterMerveille(const Merveille& merveille) {
        merveilles.push_back(merveille);
    }
    void ajouterBatiment(const Batiment& batiment) {
        merveilles.push_back(batiment);
    }
    void ajouterGuilde(const Guilde& guilde) {
        merveilles.push_back(guilde);
    }
    void ajouterJetonProgres(const JetonsProgres& jeton) {
        merveilles.push_back(jeton);
    }
};

ostream& operator<<(ostream& f, const Joueur& joueur);

