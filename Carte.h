#pragma once

#include <iostream>
#include <string>
#include <list>

//enum class ressource {Papyrus, Verre, Pierre, Argile, Bois};
//enum class symbole_scientifique {Roue, Compas, Pilon, Tablette, Lyre, Mesure, Telescope};

enum class type_batiment {Militaire, Scientifique, Manufacture, Premiere, Civile, Commerce, Guilde, Merveille};
enum class jeton_progres{Agriculture, Architecture, Economie, Loi, Maconnerie, Mathematiques,Philosophie, Strategie, Theologie, Urbanisme};
enum class phase_jeu {START, AGE_I, AGE_II, AGE_III, END};

enum class ressource {Bouclier, Papyrus, Verre, Pierre, Argile, Bois, Roue, Compas, Pilon, Tablette, Lyre, Mesure, Telescope};
// toutes les ressources génériques sont centralisées dans cet enum : 
// Boucliers, Matières Premières, Produits Manufacturés, Symbols Scientifiques

class GameException {
	public:
		GameException(const std::string& i) :info(i) {}
		std::string getInfo() const { return info; }
	private:
		std::string info;
	};

class Carte {
    public: 

        Carte(std::string nom, type_batiment type, std::list<ressource> cost_r = {}, unsigned int cost_m = 0, unsigned int argent = 0, unsigned int pt_victoire = 0);

        // GETTERS
        std::string getNom() const { return nom ; }
        type_batiment getType() const { return type ;}
        unsigned int getCoutArgent() const { return cost_m ; }
        unsigned int getRewardArgent() const { return argent ; }
        unsigned int getPointVictoire() const { return pt_victoire ;}
        std::list<ressource> getCoutRessource() const { return cost_r ;}

        // SETTERS
        void setNom(std::string new_nom){ nom = new_nom ;}
        void setType(type_batiment new_type) {type = new_type ;}
        void setCoutArgent(unsigned int new_cost_m) { cost_m = new_cost_m ;}
        void setRewardArgent(unsigned int new_argent) { argent = new_argent ;}
        void setPointVictoire(unsigned int new_pt_victoire) { pt_victoire = new_pt_victoire ;}
        void setCoutRessource(std::list<ressource> cost) ;


    private:
        std::string nom ;
        type_batiment type ;
        std::list<ressource> cost_r ; // cout en ressources
        unsigned int cost_m ; // cout en argent

        unsigned int argent ;
        unsigned int pt_victoire ;

        bool checkCoutRessources(std::list<ressource> cost_r) const;
        // vérifier que les ressources entrées appartiennent à la bonne catégorie
};

class Batiment : public Carte { 
    // Civil, Scientifique, Militaire, Ressources
    public:

    private:
        std::list<ressource> production ;
        Batiment& chained_by ;
};

class Guilde : public Batiment {
    public:
    private:
        type_batiment affectation ; 
        bool usurier ; 
};

class Commerce : public Batiment {
    public:
    private:
};

class Merveille : public Carte {
    public:
    private:
        bool replay ; 
};
