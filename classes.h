#pragma once 

#include <iostream>
#include <string>

using namespace std ; 

namespace Game {

    // classe pour gérer les exceptions dans le jeu
	class GameException {
	public:
		GameException(const string& i) :info(i) {}
		string getInfo() const { return info; }
	private:
		string info;
	};

    enum class TypeBatiment {Militaire, Production, Civil, Scientifique, Commerce, Guilde};

    enum class Ressource {Argile, Bois, Pierre, Verre, Papyrus}; //Bouclier

    class Batiment {
        private:
            //const string nom ; géré par la classe Carte

            // comme il y'aura des cartes en doubles : utiliser le nom des cartes pour le chaînage ?
            const Batiment& chainage_to ;
            const Batiment& chainage_by ;
            const TypeBatiment type ;
            const int age ; // plus pertinent de mettre age dans Batiment comme les Merveilles n'ont pas d'Age
            // ajouter Points de Victoire aux Cartes ? 

        public: 

            const Batiment& getChainageBy() const ; 
            const Batiment& getChainageTo() const ;
            const TypeBatiment getTypeBatiment() const { return type;};
            const int getAge() const { return age;};
    };

    class Merveille {
        // idée d'architecture : classe Merveille "modèle" pour gérer les coûts, les points de victoires...
        // CHAQUE Merveille aura sa propre sous-classe héritant du modèle pour gérer chaques effets 

        private:
            //const string nom ;  // géré par la classe Carte
            Batiment* carte_activation ; // bool active ; 
            //const Ressource* cost ; // géré par la classe Carte normalement
            const bool rejouer ; 
            const int points_victoire ;

        public : 
            //const string getNom() const {return nom;};

            bool merveilleActive() const {return carte_activation != nullptr;};
            //const Ressource* getCost() const ;
            const bool getRejouer() const {return rejouer;}; 
            const int getPointsVictoire() const {return points_victoire;};
        
            ~Merveille() = default ; 
            // il faudra peut être gérer le tableau pour les coûts en fonction de comment on s'en occupe

            Merveille(const Merveille& m) = default ; 
            Merveille& operator=(const Merveille& m) = default ;
            // autoriser la recopie / duplication des Merveilles ?
            
    };

}
