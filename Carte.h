#pragma once

#include <iostream>
#include <string>
#include <list>
#include <set>
#include "Type.h"


//enum class Ressources {Papyrus, Verre, Pierre, Argile, Bois};
//enum class symbole_scientifique {Roue, Compas, Pilon, Tablette, Lyre, Mesure, Telescope};
//enum class Types {Militaire, Scientifique, Manufacture, Premiere, Civil, Commerce, Guilde, Merveille};
//enum class jeton_progres{Agriculture, Architecture, Economie, Loi, Maconnerie, Mathematiques,Philosophie, Strategie, Theologie, Urbanisme};
//enum class phase_jeu {START, AGE_I, AGE_II, AGE_III, END};

//enum class Ressources {Bouclier, Papyrus, Verre, Pierre, Argile, Bois, Roue, Compas, Pilon, Tablette, Lyre, Mesure, Telescope};
// toutes les Ressourcess génériques sont centralisées dans cet enum : 
// Boucliers, Matières Premières, Produits Manufacturés, Symbols Scientifiques

std::set<Ressources> getMatierePremiere();
std::set<Ressources> getProduitManufacture();
std::set<Ressources> getRessource();
std::set<Ressources> getSymboleScientifique();

std::string tostringRessources(Ressources r);
std::string tostringType(Types t);

class Carte {
    public: 

        Carte(std::string nom, Types type, std::list<Ressources> cost_r = {}, unsigned int cost_m = 0, unsigned int argent = 0, unsigned int pt_victoire = 0);

        // GETTERS
        std::string getNom() const { return nom ; }
        Types getType() const { return type ;}
        unsigned int getCoutArgent() const { return cost_m ; }
        unsigned int getRewardArgent() const { return argent ; }
        unsigned int getPointVictoire() const { return pt_victoire ;}
        std::list<Ressources> getCoutRessource() const { return cost_r ;}

        // SETTERS
        void setNom(std::string new_nom){ nom = new_nom ;}
        //void setType(Types new_type) {type = new_type ;} //  attribut const
        void setCoutArgent(unsigned int new_cost_m) { cost_m = new_cost_m ;}
        void setRewardArgent(unsigned int new_argent) { argent = new_argent ;}
        void setPointVictoire(unsigned int new_pt_victoire) { pt_victoire = new_pt_victoire ;}
        void setCoutRessource(std::list<Ressources> cost) ;

        // UTILS
        bool achetableRessource(std::list<Ressources> buy) const ; 
    
    protected : 

        bool checkTypeRessources(std::list<Ressources> cost_r, std::set<Ressources> subset) const;
        // vérifier que les Ressourcess entrées appartiennent à la bonne catégorie

    private:
        std::string nom ;
        const Types type ;
        std::list<Ressources> cost_r ; // cout en Ressourcess
        unsigned int cost_m ; // cout en argent

        unsigned int argent ;
        unsigned int pt_victoire ;
};

std::ostream& operator<<(std::ostream& f, Carte c);

class Batiment : public Carte { 
    // Civil, Scientifique, Militaire, Ressources
    public:

        Batiment(
            std::string nom, Types type, 
            std::list<Ressources> cost_r={}, unsigned int cost=0, 
            unsigned int argent=0, unsigned int pt_victoire=0,

            std::list<Ressources> production={}, std::string chained_by=""
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

class Commerce : public Batiment {
    public:
    private:
};

class Merveille : public Carte {
    public:
        Merveille(std::string nom, Types type=Types::Merveille, std::list<Ressources> cost_r = {}, unsigned int cost_m = 0, unsigned int argent = 0, unsigned int pt_victoire = 0, bool b=false) : Carte(nom, type, cost_r, cost_m, argent, pt_victoire), replay(b) {
            if(type!=Types::Merveille){
                throw GameException("Merveille instanciée avec un type autre que Merveille");
            }
        }; 

        //GETTERS
        bool getReplay() const { return replay ;}

        //SETTERS
        void setReplay(bool b) { replay = b ;}

    private:
        bool replay ; 
};
