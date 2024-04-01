#ifndef CARTE_H_INCLUDED
#define CARTE_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

enum Age {AGE_I , AGE_II, AGE_III};

enum Ressource {Argile, Bois, Pierre, Verre, Papyrus, Aucune};

typedef struct Effet{
    Ressource ressource;
    int recompense;
}Effet;

class Carte{
    private:
        string nom;
        Effet effet;
        Age age;
        int prix;
        string condition;

    public:
        Carte (string n, Age g, int p, Effet e, string c): nom(n), age(g), prix(p), effet(e), condition(c) {};
        Carte(const Carte& c) = delete;
        Carte& operator=(const Carte& c) = delete ;



        string ageToString(Age age);
        string RessourceToString(Ressource ressource);

        string const getNom() ;
        int const getPrix();
        string const getAge() ;
        string const getRessource() ;
        int const getRecompense();
        string const getCondition();


};

#endif // CARTE_H_INCLUDED
