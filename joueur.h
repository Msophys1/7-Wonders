#include <iostream>
using namespace std;

enum Ressources { bois, argile, pierre };
enum Symboles_Progres { philosophie, architecture, economie, agriculture, loi, maconnerie, mathemathiques, strategie, theologie, urbanisme };

class Joueur {
private:
    int id;
    Ressources ressources[100];
    Symboles_Progres symboles_progres[7];
    int nombre_ressources;
    int nombre_symboles_progres;

public:
    // Constructeur
    Joueur(int idJoueur, Ressources joueurRessources[], Symboles_Progres joueurSymbolesProgres[], int numRessources, int numSymbolesProgres);

    // Destructeur
    ~Joueur() = default;

    // GET
    int getIdJoueur() const { return id; }
    const Ressources* getRessources() const { return ressources; }
    const Symboles_Progres* getSymbolesProgres() const { return symboles_progres; }

    // Ajouter ressources
    void ajouterRessource(Ressources nouvelleRessource);

    // Ajouter symbole
    void ajouterSymboleProgres(Symboles_Progres nouveauSymboleProgres);
};

