#include <iostream>
#include <string>
#include <map>
#include "Type.h"
#include "Carte.h"
using namespace std;

class Joueur {
private:
    int id;
    string nom;
    vector<Carte> merveillesJoueur1;

    // Gestion des ressources
    int nombreRessources = 0;
    Ressources ressourcesObtenus[100];

    // Gestion des symboles scientifiques
    int nombreSymbolesScientifiques = 0;
    SymboleScientifiques symbolesScientifiquesObtenus[7];

    // Gestion des jetons progres
    int nombres_jetons_progres = 0;
    JetonsProgres jetonsPogresObtenus[10];
    int pointsVictoireJetons = 0; // Points de victoire additionnels pour les jetons de progrès possédés.

    // Couts réduits
    int coutReduitConstruction = 0; // Réduit le coût de construction des cartes ou des merveilles, facilitant leur acquisition.
    int coutReduitCartesBleues = 0; // Pour gérer la réduction de coût des cartes bleues.

    // Effets
    bool effetRejouer = false; // Indique si le joueur peut rejouer (effet de Theologie).
    bool effetEconomie = false; // Un drapeau qui, lorsqu'il est vrai, indique que le joueur bénéficie d'un effet économique spécial (par exemple, recevoir des pièces supplémentaires).

    // Autres ressources
    int pointsDeVictoire = 0; // Compte les points de victoire accumulés par le joueur au cours du jeu.
    int pieces = 0; // Représente les pièces de monnaie que le joueur a accumulées, utilisées pour divers achats ou actions dans le jeu.
    int puissanceMilitaire = 0; // Indique la force militaire du joueur, influençant les confrontations militaires avec d'autres joueurs.

public:
    // Constructeur
    Joueur(int idJoueur, string nom, Ressources *joueurRessources, JetonsProgres *joueurSymbolesProgres, int numRessources, int numSymbolesProgres);

    // Accesseurs en lecture

    int getId() const { return id;}
    string getNom() const { return nom; }
    int getNbRessources() const { return nombreRessources; }
    const Ressources* getRessources() const { return ressourcesObtenus; }
    int getNbSymbolesScientifiques() const { return nombreSymbolesScientifiques; }
    const SymboleScientifiques* getSymbolesScientifiques() const { return symbolesScientifiquesObtenus; }
    int getNbJetonsProgres() const { return nombres_jetons_progres; }
    const JetonsProgres* getJetonsProgres() const { return jetonsPogresObtenus; }
    int getPointsVictoireJetons() const { return pointsVictoireJetons; }
    int getCoutReduitConstruction() const { return coutReduitConstruction; }
    int getCoutReduitCartesBleues() const { return coutReduitCartesBleues; }
    bool getEffetRejouer() const { return effetRejouer; }
    bool getEffetEconomie() const { return effetEconomie; }
    int getPointsDeVictoire() const { return pointsDeVictoire; }
    int getPieces() const { return pieces; }
    int getPuissanceMilitaire() const { return puissanceMilitaire; }


    // Accesseurs en ecriture
    void ajouterRessource(const Ressources& ressource);
    void ajouterSymboleScientifique(const SymboleScientifiques& symbole);
    void ajouterJetonsProgres(const JetonsProgres& jeton);

    void ajouterPointsDeVictoire(int points) { pointsDeVictoire += points; } // Ajoute des points de victoire au total du joueur. Les points de victoire sont cruciaux pour gagner le jeu.
    void augmenterPuissanceMilitaire(int augmentation) { puissanceMilitaire += augmentation; } // Augmente la puissance militaire du joueur, ce qui peut influencer les résultats des confrontations militaires.
    void ajouterSymboleScientifique(SymboleScientifiques symbole) { nombreSymbolesScientifiques++; symbolesScientifiquesObtenus[nombreSymbolesScientifiques] = symbole;} // Incrémente le compteur pour un symbole scientifique spécifique, indiquant que le joueur a collecté un autre de ce symbole.

    void reduireCoutCartesBleues(int reduction) { coutReduitCartesBleues += reduction; } // Réduit le coût des cartes bleues pour le joueur, facilitant leur acquisition.
    void reduireCoutConstruction(int reduction) { coutReduitConstruction += reduction; } // Réduit le coût de construction, permettant au joueur d'acquérir des cartes ou de construire des merveilles avec moins de ressources.

    void ajouterPointsDeVictoirePourJetons(int points) { pointsVictoireJetons += points; } // Ajoute des points de victoire supplémentaires basés sur les jetons de progrès que le joueur possède.

    void activerEffetRejouer() { effetRejouer = true; } // Permet au joueur de rejouer grâce à l'effet d'un jeton de progrès.
    void activerEffetEconomie() {effetEconomie = true; } // Active un effet économique spécial pour le joueur, offrant potentiellement des avantages financiers.

    void ajouterPointsDeVictoireDirect(int points) { pointsDeVictoire += points; } // Ajoute directement une quantité spécifiée de points de victoire au total de points de victoire du joueur.
    void ajouterPieces(int nombre) { pieces += nombre; } // Ajoute un nombre spécifié de pièces à la réserve du joueur. Peut être utilisé pour les récompenses ou le paiement.
    void activerEffetChainage(int niveau);



    // Destructeur
    ~Joueur() = default;

};
