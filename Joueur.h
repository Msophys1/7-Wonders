#include <iostream>
#include <string>
#include <map>
#include "Type.h"
#include "Carte.h"
using namespace std;

class Joueur {
private:
    string nom;
    vector<Carte> cartes;
    vector<Carte> merveilles;
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
    void setCartes(const vector<Carte>& nouvellesCartes) { cartes = nouvellesCartes; }
    void setMerveilles(const vector<Carte>& nouvellesMerveilles) { merveilles = nouvellesMerveilles; }
    void setJetonsProgres(const vector<JetonsProgres>& nouveauxJetons) { jetonsProgres = nouveauxJetons; }


    // Getters
    const string& getNom() const { return nom; }
    bool getEffetRejouer() const { return effetRejouer; }
    int getPointsDeVictoire() const { return pointsDeVictoire; }
    int getPieces() const { return pieces; }
    int getPuissanceMilitaire() const { return puissanceMilitaire; }
    Joueur* getAdversaire() const { return adversaire; }
    const vector<Carte>& getCartes() const { return cartes; }
    const vector<Carte>& getMerveilles() const { return merveilles; }
    const vector<JetonsProgres>& getJetonsProgres() const { return jetonsProgres; }
};

ostream& operator<<(ostream& f, const Joueur& joueur);

