#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

enum Age {AGE_I , AGE_II, AGE_III};

enum Ressource {Argile, Bois, Pierre, Verre, Papyrus, Aucune};

enum Batiment {
    Civil,
    Commercial,
    Scientifique,
    Militaire,
    Guildes,
    Merveilles,
    Conflit
};

enum SymboleScientifique {
    Roue,
    Balance,
    Tablet,
    Pierre,
    Ampoule,
    Loupe,
    Compas
};

enum Construction {
    grise,
    marron,
    jaune,
    rouge,
    merveille
};

typedef struct Effet{
    Ressource ressource;
    Ressource ressource1;
    Ressource ressource2;
    Ressource ressource3;
    Ressource ressource4;
    int pointsDeVictoire;
    int nbDeBouclier;
    int recompense;
    string condition;
    SymboleScientifique symbole;
    Construction construct;
    Construction construct1;
    bool EntreLesDeuxCites;
}Effet;

typedef struct Prix{
    Ressource ressource;
    Ressource ressource1;
    Ressource ressource2;
    Ressource ressource3;
    Ressource ressource4;
    int cost;
    string condition;
}Prix;

class Carte{
    private:
        string nom;
        Effet effet;
        Age age;
        Prix prix;

    public:
        Carte (string n, Age g, Prix p, Effet e): nom(n), age(g), prix(p), effet(e) {};
        Carte(const Carte& c) = delete;
        Carte& operator=(const Carte& c) = delete ;




        string const getNom();
        Prix const getPrix();
        Age const getAge();
        Effet const getEffet();





};

#endif // CARTE_H_INCLUDED
