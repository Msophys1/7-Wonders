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
            const string chainage_to ; // précédemmeent const Batiment&
            const string chainage_by ;
            const TypeBatiment type ;
            const int age ; // plus pertinent de mettre age dans Batiment comme les Merveilles n'ont pas d'Age
            // ajouter Points de Victoire aux Cartes ? 

        public: 

            const string getChainageBy() const { return chainage_by;};
            const string getChainageTo() const { return chainage_to;};
            const TypeBatiment getTypeBatiment() const { return type;};
            const int getAge() const { return age;};

            ~Batiment() = default ;
            Batiment(const Batiment& b) = default ; // on autorise la duplication
            Batiment& operator=(const Batiment& b) = default ;     
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
            // la Merveille n'est pas responsable du cycle de vie de la carte sur laquelle elle se feed (à priori)
            // il faudra peut être gérer le tableau pour les coûts en fonction de comment on s'en occupe

            Merveille(const Merveille& m) = delete ; // chaque merveille étant unique, leur recopie est interdite
            // décision peut être amenée à changer pendant le développement de l'architecture
            Merveille& operator=(const Merveille& m) = delete ;
            
    };

}
