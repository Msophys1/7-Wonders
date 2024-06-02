#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <random>


std::set<ressource> getMatierePremiere();
std::set<ressource> getProduitManufacture();
std::set<ressource> getRessource();
std::set<ressource> getSymboleScientifique();

std::string tostringRessources(ressource r);
std::string tostringType(type_batiment t);
std::string tostringAge(phase_jeu p);

phase_jeu& operator++(phase_jeu& phase);

void displayRessources(std::list<ressource> r);

class GameException {
	public:
		GameException(const std::string& i) :info(i) {}
		std::string getInfo() const { return info; }
	private:
		std::string info;
};

// FORWARD DECLARATION
class Perk ;
class Joueur ;
class Box ; 

class Carte { // ABSTRACT 

    // une fois créée par le contrôlleur Box (qui les gère),
    // les cartes sont immutables et toujours manipulés avec des pointeurs const

    public: 

        Carte(std::string nom, type_batiment type, phase_jeu age=phase_jeu::AGE_I, std::list<ressource> cost_r = {}, unsigned int cost_m = 0, unsigned int argent = 0, unsigned int pt_victoire = 0);

        // GETTERS
        std::string getNom() const { return nom ; }
        type_batiment getType() const { return type ;}
        phase_jeu getAge() const { return c_age ; }
        unsigned int getCoutArgent() const { return cost_m ; }
        unsigned int getRewardArgent() const { return argent ; }
        unsigned int getPointVictoire() const { return pt_victoire ;}
        std::list<ressource> getCoutRessource() const { return cost_r ;}

        // SETTERS
        void setNom(std::string new_nom){ nom = new_nom ;}
        //void setType(type_batiment new_type) {type = new_type ;} //  attribut const
        void setAge(phase_jeu p){ c_age = p ;}
        void setCoutArgent(unsigned int new_cost_m) { cost_m = new_cost_m ;}
        void setRewardArgent(unsigned int new_argent) { argent = new_argent ;}
        void setPointVictoire(unsigned int new_pt_victoire) { pt_victoire = new_pt_victoire ;}
        void setCoutRessource(std::list<ressource> cost) ;

        // UTILS
        std::list<ressource> achetableRessource(std::list<ressource> buy) const ; 
        // retourne la liste des ressources manquante pour acheter la Carte

        virtual void affichage() const ;
        virtual void onBuild(Joueur* j) const = 0; // Joueur qui a construit la carte
    
    protected : 

        bool checkTypeRessources(std::list<ressource> cost_r, std::set<ressource> subset) const;
        // vérifier que les ressources entrées appartiennent à la bonne catégorie

    private:
        std::string nom ;
        const type_batiment type ;
        phase_jeu c_age ; 
        std::list<ressource> cost_r ; // cout en ressources
        unsigned int cost_m ; // cout en argent

        unsigned int argent ;
        unsigned int pt_victoire ;
};

std::ostream& operator<<(std::ostream& f, const Carte& c);

template <typename T>
void displayCards(std::vector<const T*> c){
    for(auto iter = c.begin() ; iter != c.end() ; ++iter){
        std::cout << **iter << std::endl  ;
    }
    return;
}

class Batiment : public Carte {
    // Civil, Scientifique, Militaire, Ressources
    public:

        Batiment(
            std::string nom, type_batiment type, phase_jeu age=phase_jeu::AGE_I,
            std::list<ressource> cost_r={}, unsigned int cost=0,
            unsigned int argent=0, unsigned int pt_victoire=0,

            std::list<ressource> prod={}, std::string chained_by=""
            );
        
        // GETTERS
        std::string getChainage() const { return chained_by;}
        std::list<ressource> getProduction() const { return production ;}

        // SETTERS
        void setChainage(std::string new_chain) { chained_by = new_chain;}
        void setProduction(std::list<ressource> new_prod) { production = new_prod ;}

        void affichage() const override ;
        void onBuild(Joueur* j) const override ; 


    private:
        std::list<ressource> production ;
        std::string chained_by ; 
};

class Commerce : public Batiment {
    // RESPONSABLE DE SA PERK !!!
    public:

        Commerce(std::string nom, type_batiment type, phase_jeu age=phase_jeu::AGE_I, std::list<ressource> cost_r={}, unsigned int cost=0, unsigned int argent=0, unsigned int pt_victoire=0, std::list<ressource> prod={}, std::string chained_by="", const Perk* perk=nullptr);
        ~Commerce();
        
        const Perk* getPerk() const { return perk; }

        void onBuild(Joueur* j) const override ;

    protected:

        const Perk* perk ;
};

class Merveille : public Commerce {
    public:
        Merveille(std::string nom, type_batiment type=type_batiment::Merveille, phase_jeu age=phase_jeu::AGE_I, std::list<ressource> cost_r = {}, unsigned int cost_m = 0, unsigned int argent = 0, unsigned int pt_victoire = 0, std::list<ressource> prod={}, std::string chained_by="", const Perk* perk=nullptr, bool b=false, Carte* f=nullptr) : 
        Commerce(nom, type, age, cost_r, cost_m, argent, pt_victoire, prod, chained_by, perk), replay(b), feed(f) {
            if(type!=type_batiment::Merveille){
                throw GameException("ERREUR: Merveille instanciée avec un type autre que Merveille");
            }
            if(chained_by != ""){
                throw GameException("ERREUR: une Merveille ne peut pas être chaîneée");
            }
        }; 

        //GETTERS
        bool getReplay() const { return replay ;}
        const Carte* getFeed() const { return feed ;}
        bool isFed() const { return feed != nullptr; }

        //SETTERS
        void setReplay(bool b) { replay = b ;}

        //void onBuild(Joueur* j) const override ; // Calls onBuild commerce

    private:

        const Carte* feed ;
        bool replay ;
};

class Guilde : public Carte {
    public:
        Guilde(
            std::string nom, type_batiment type, phase_jeu age=phase_jeu::AGE_I,
            std::list<ressource> cost_r={}, unsigned int cost=0,
            unsigned int argent=0, unsigned int pt_victoire=0,

            std::list<type_batiment> affectation={}, bool usurier=false
            );

        unsigned int ptVictoireFinJeu(Joueur* j) const ;
        void rewardArgent(Joueur* j) const ;

        void onBuild(Joueur* j) const override ;

    private:
        std::list<type_batiment> affectation ; 
        bool usurier ; 
};


class Perk { // ABSTRACT

    public: // PERK: ON CALL
    
        virtual void onCall(Joueur* j) const = 0 ; // PURE VIRTUAL
        // on prend en paramètre le joueur qui a construit la carte

        //~Perk(){} // vtable error paranoia ???
        //bool isPolyRes(); 

    private:

};

class Perk_CoinPerCard : public Perk {

    public: 
        Perk_CoinPerCard(unsigned int coin, type_batiment card):coin(coin), card(card){}
        //~Perk_CoinPerCard(){};

        void gainCoinPerCard(Joueur* j) const ;
        void onCall(Joueur* j) const override ;

    private: // perk settings
        unsigned int coin ; // nombre de pièces que l'on gagne par carte
        type_batiment card ; // type de carte sur laquelle le calcul se base

}; 

class Perk_Destruction : public Perk { // requires player interaction
    public:
        Perk_Destruction(type_batiment c);

        void destruction(Joueur* j) const ; 
        void onCall(Joueur* j) const override; 
    private:
        type_batiment card ; // type de Bâtiment autorisé à la destruction
};

class Perk_FixedTrade : public Perk {

    public:
        Perk_FixedTrade(std::list<ressource> res, unsigned int coin): res(res), coin(coin){}

        void setFixedTrade(Joueur* j) const ;
        void onCall(Joueur* j) const override ; 
    private: // perk settings
        std::list<ressource> res ; // ressource pour laquelle le prix de trade est fixé
        unsigned int coin ; // prix fixé

};

class Perk_Classic : public Perk { // PERKS W/O SETTINGS
// PICK JETONS
// FREE CONSTRUCTION FROM DEFAUSSE
// SACCAGE
    public: 
        Perk_Classic(unsigned int id, const Box* box);

        void saccage(Joueur* j) const ;
        void freeConstructionFromDefausse(Joueur* j) const;
        void pickJeton(Joueur* j) const;
        void onCall(Joueur* j) const override;
    private:
        unsigned int id ;
        const Box* box ; 
};

/* 

// La Perk PolyRessource est abandonnée
// On considère à la place que si un bâtiment de Commerce ou une Merveille produit des ressources,
// il s'agit d'une poly ressource

class Perk_PolyRessource : public Perk {
    public:
        Perk_PolyRessource(std::list<ressource> res):res(res){}

        std::list<ressource> getPolyRessources() const ;
        void onCall(Joueur* j) const override ; 
    private:
        std::list<ressource> res;
};
*/
