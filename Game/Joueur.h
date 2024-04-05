#include <iostream>
#include <string>
#include <map>
#include "Type.h"


class Joueur {
private:
    int id;
    std::string nom; // Stocke le nom du joueur. Utile pour l'identification et l'affichage.
    Ressources ressources[30];
    int nombre_ressources;
    int nombre_symboles_progres;
    int pointsDeVictoire = 0; // Compte les points de victoire accumulés par le joueur au cours du jeu.
    int pieces = 0; // Représente les pièces de monnaie que le joueur a accumulées, utilisées pour divers achats ou actions dans le jeu.
    int puissanceMilitaire = 0; // Indique la force militaire du joueur, influençant les confrontations militaires avec d'autres joueurs.
    bool effetEconomie = false; // Un drapeau qui, lorsqu'il est vrai, indique que le joueur bénéficie d'un effet économique spécial (par exemple, recevoir des pièces supplémentaires).
    int coutReduitConstruction = 0; // Réduit le coût de construction des cartes ou des merveilles, facilitant leur acquisition.
    int coutReduitCartesBleues = 0; // Pour gérer la réduction de coût des cartes bleues.
    int pointsVictoireJetons = 0; // Points de victoire additionnels pour les jetons de progrès possédés.
    bool effetRejouer = false; // Indique si le joueur peut rejouer (effet de Theologie).
    bool effetChainage = false; // Indique si un effet de chainage est activé (effet d'Urbanisme).

public:
    Joueur(int idJoueur, std::string nom, Ressources *joueurRessources, JetonsProgres *joueurSymbolesProgres, int numRessources,
           int numSymbolesProgres);

    std::map<SymboleScientifiques, int> scientificSymbols;

    std::string getNom() const { return nom; }
    // Retourne le nom du joueur. Utile pour l'affichage et les références au joueur.

    int getId() const { return id; }

    const Ressources *getRessources() const { return ressources; }

    void ajouterPieces(int nombre) { pieces += nombre; }
    // Ajoute un nombre spécifié de pièces à la réserve du joueur. Peut être utilisé pour les récompenses ou le paiement.

    void ajouterPointsDeVictoire(int points) { pointsDeVictoire += points; }
    // Ajoute des points de victoire au total du joueur. Les points de victoire sont cruciaux pour gagner le jeu.

    void augmenterPuissanceMilitaire(int augmentation) { puissanceMilitaire += augmentation; }
    // Augmente la puissance militaire du joueur, ce qui peut influencer les résultats des confrontations militaires.

    void activerEffetEconomie() {effetEconomie = true; }
    // Active un effet économique spécial pour le joueur, offrant potentiellement des avantages financiers.

    void reduireCoutConstruction(int reduction) { coutReduitConstruction += reduction; }
    // Réduit le coût de construction, permettant au joueur d'acquérir des cartes ou de construire des merveilles avec moins de ressources.

    void ajouterSymboleScientifique(SymboleScientifiques symbole) {
        scientificSymbols[symbole]++;
    }
    // Incrémente le compteur pour un symbole scientifique spécifique, indiquant que le joueur a collecté un autre de ce symbole.

    void reduireCoutCartesBleues(int reduction) { coutReduitCartesBleues += reduction; }
    // Réduit le coût des cartes bleues pour le joueur, facilitant leur acquisition.

    void ajouterPointsDeVictoirePourJetons(int points) { pointsVictoireJetons += points; }
    // Ajoute des points de victoire supplémentaires basés sur les jetons de progrès que le joueur possède.

    void activerEffetRejouer() { effetRejouer = true; }
    // Permet au joueur de rejouer grâce à l'effet d'un jeton de progrès.

    void activerEffetChainage(int niveau) {
         effetChainage = true;
    }
    void ajouterPointsDeVictoireDirect(int points) {
        // Ajoute directement une quantité spécifiée de points de victoire au total de points de victoire du joueur.
        pointsDeVictoire += points;
    }

    ~Joueur() = default;

};
