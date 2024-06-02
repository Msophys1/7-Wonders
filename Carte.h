#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <random>

#include "Type.h"


//enum class Types {Militaire, Scientifique, Manufacture, Premiere, Civil, Commerce, Guilde, Merveille};
//enum class jeton_progres{Agriculture, Architecture, Economie, Loi, Maconnerie, Mathematiques,Philosophie, Strategie, Theologie, Urbanisme};
enum class phase_jeu {START=0, AGE_I=1, AGE_II=2, AGE_III=3, END=4};
//enum class Ressources {Bouclier=0, Papyrus=1, Verre=2, Pierre=3, Argile=4, Bois=5, Roue=6, Compas=7, Pilon=8, Tablette=9, Lyre=10, Mesure=11, Telescope=12};
// toutes les Ressourcess génériques sont centralisées dans cet enum : 
// Boucliers, Matières Premières, Produits Manufacturés, Symbols Scientifiques

std::set<Ressources> getMatierePremiere();
std::set<Ressources> getProduitManufacture();
std::set<Ressources> getRessources();
std::set<Ressources> getSymboleScientifique();

std::string tostringRessourcess(Ressources r);
std::string tostringType(Types t);
std::string tostringAge(phase_jeu p);

phase_jeu& operator++(phase_jeu& phase);

//void displayRessourcess(std::list<Ressources> r);
/*
class GameException {
	public:
		GameException(const std::string& i) :info(i) {}
		std::string getInfo() const { return info; }
	private:
		std::string info;
};
*/

class Carte {
    // une fois créée par le contrôlleur Box (qui les gère),
    // les cartes sont immutables et toujours manipulés avec des pointeurs const

    public: 

        Carte(std::string nom, Types type, phase_jeu age=phase_jeu::AGE_I, std::list<Ressources> cost_r = {}, unsigned int cost_m = 0, unsigned int argent = 0, unsigned int pt_victoire = 0);

        // GETTERS
        std::string getNom() const { return nom ; }
        Types getType() const { return type ;}
        phase_jeu getAge() const { return c_age ; }
        unsigned int getCoutArgent() const { return cost_m ; }
        unsigned int getRewardArgent() const { return argent ; }
        unsigned int getPointVictoire() const { return pt_victoire ;}
        std::list<Ressources> getCoutRessources() const { return cost_r ;}

        // SETTERS
        void setNom(std::string new_nom){ nom = new_nom ;}
        //void setType(Types new_type) {type = new_type ;} //  attribut const
        void setAge(phase_jeu p){ c_age = p ;}
        void setCoutArgent(unsigned int new_cost_m) { cost_m = new_cost_m ;}
        void setRewardArgent(unsigned int new_argent) { argent = new_argent ;}
        void setPointVictoire(unsigned int new_pt_victoire) { pt_victoire = new_pt_victoire ;}
        void setCoutRessources(std::list<Ressources> cost) ;

        // UTILS
        std::list<Ressources> achetableRessources(std::list<Ressources> buy) const ; 
        // retourne la liste des Ressourcess manquante pour acheter la Carte
    
    protected : 

        bool checkTypeRessourcess(std::list<Ressources> cost_r, std::set<Ressources> subset) const;
        // vérifier que les Ressourcess entrées appartiennent à la bonne catégorie

    private:
        std::string nom ;
        const Types type ;
        phase_jeu c_age ; 
        std::list<Ressources> cost_r ; // cout en Ressourcess
        unsigned int cost_m ; // cout en argent

        unsigned int argent ;
        unsigned int pt_victoire ;
};

std::ostream& operator<<(std::ostream& f, Carte c);

template <typename T>
void displayCards(std::vector<const T*> c){
    for(auto iter = c.begin() ; iter != c.end() ; ++iter){
        std::cout << **iter << std::endl  ;
    }
    return;
}

class Batiment : public Carte { 
    // Civil, Scientifique, Militaire, Ressourcess
    public:

        Batiment(
            std::string nom, Types type, phase_jeu age=phase_jeu::AGE_I,
            std::list<Ressources> cost_r={}, unsigned int cost=0,
            unsigned int argent=0, unsigned int pt_victoire=0,

            std::list<Ressources> prod={}, std::string chained_by=""
            );
        
        // GETTERS
        std::string getChainage() const { return chained_by;}
        std::list<Ressources> getProduction() const { return production ;}

        // SETTERS
        void setChainage(std::string new_chain) { chained_by = new_chain;}
        void setProduction(std::list<Ressources> new_prod) { production = new_prod ;}


    private:
        std::list<Ressources> production ;
        std::string chained_by ; 
};

class Guilde : public Carte {
    public:
    private:
        Types affectation ; 
        bool usurier ; 
};

class Commerce : public Batiment { // onBuild method
    public:
    private:
};

class Merveille : public Carte {
    public:
        Merveille(std::string nom, Types type=Types::Merveille, phase_jeu age=phase_jeu::AGE_I, std::list<Ressources> cost_r = {}, unsigned int cost_m = 0, unsigned int argent = 0, unsigned int pt_victoire = 0, bool b=false, Carte* f=nullptr) : Carte(nom, type, age, cost_r, cost_m, argent, pt_victoire), replay(b), feed(f) {
            if(type!=Types::Merveille){
                throw GameException("Merveille instanciée avec un type autre que Merveille");
            }
        };

        //GETTERS
        bool getReplay() const { return replay ;}
        const Carte* getFeed() const { return feed ;}

        //SETTERS
        void setReplay(bool b) { replay = b ;}

    private:

        const Carte* feed ;
        bool replay ; 
};
