#include "Carte.h"
#include "GameManager.h"

std::set<Ressources> getMatierePremiere() {
    return {
            Ressources::Pierre,
            Ressources::Argile,
            Ressources::Bois
    };
}

std::set<Ressources> getProduitManufacture() {
    return {
            Ressources::Papyrus,
            Ressources::Verre
    };
}

std::set<Ressources> getRessource() {
    return {
            Ressources::Pierre,
            Ressources::Argile,
            Ressources::Bois,
            Ressources::Papyrus,
            Ressources::Verre
    };
}

std::set<Ressources> getSymboleScientifique() {
    return {
            Ressources::Roue,
            Ressources::Compas,
            Ressources::Pilon,
            Ressources::Tablette,
            Ressources::Lyre,
            Ressources::Mesure,
            Ressources::Telescope
    };
}

std::string tostringRessources(Ressources r){
    switch(r) {
        case Ressources::Roue : return "Roue" ;
        case Ressources::Compas : return "Compas" ;
        case Ressources::Pilon : return "Pilon" ;
        case Ressources::Tablette : return "Tablette" ;
        case Ressources::Lyre : return "Lyre" ;
        case Ressources::Mesure : return "Mesure" ;
        case Ressources::Telescope : return "Telescope" ;
        case Ressources::Bouclier : return "Bouclier" ;
        case Ressources::Papyrus : return "Papyrus" ;
        case Ressources::Verre : return "Verre" ;
        case Ressources::Pierre : return "Pierre" ;
        case Ressources::Argile : return "Argile" ;
        case Ressources::Bois : return "Bois" ;
        default : throw GameException("Ressource inconnue") ;
    };
}

std::string tostringType(Types t){
    switch(t){
        case Types::Civil : return "Civil" ;
        case Types::Militaire : return "Militaire" ;
        case Types::Scientifique : return "Scientifique" ;
        case Types::Manufacture : return "Manufacture" ;
        case Types::Premiere : return "Premiere" ;
        case Types::Commerce : return "Commerce" ;
        case Types::Guilde : return "Guilde" ;
        case Types::Merveille : return "Merveille" ;
        default : throw GameException("Batiment inconnue") ;
    };
}


bool Carte::checkTypeRessources(std::list<Ressources> cost_r, std::set<Ressources> subset) const {
    //std::set<Ressources> standard_Ressourcess = getRessource();
    for(auto iter = cost_r.begin() ; iter != cost_r.end() ; ++iter ) { // list iterator
        if( subset.find(*iter) == subset.end() ) {
            //std::cout << "WARNING : INVALID RESSOURCE LIST" << std::endl ;
            return false ;
        }
    }
    //std::cout << "CORRECT RESSOURCE LIST" << std::endl ;
    return true ;
}

Carte::Carte(std::string n, Types t, std::list<Ressources> c_r, unsigned int c_m, unsigned int arge, unsigned int vic):nom(n), type(t), argent(arge), pt_victoire(vic){

    if(c_r.size() > 5){
        throw GameException("ERREUR : trop de Ressourcess dans le coût de la carte instanciée") ;
    }

    cost_m = c_m ;

    if(!checkTypeRessources(c_r, getRessource())){
        throw GameException("ERREUR : list de Ressourcess invalide dans la carte instanciée (matières premières ou produits manufacturés SEULEMENT)") ;
    }
    cost_r = c_r ;
}

void Carte::setCoutRessource(std::list<Ressources> cost){
    if(checkTypeRessources(cost, getRessource()) && cost.size() <= 5) {
        cost_r = cost ;
    } else {
        throw GameException("ERREUR : list de Ressourcess invalide dans la carte à modifier (matières premières ou produits manufacturés SEULEMENT)") ;
    }
}

bool Carte::achetableRessource(std::list<Ressources> buy) const {
    if(cost_r.empty()) { return true ; }
    if(cost_r.size() > buy.size()) { return false ; }

    std::list<Ressources> pop_buy = buy ;

    for(auto iter = cost_r.begin() ; iter != cost_r.end() ; ++iter){ // parcours les Ressourcess demandées
        std::cout << "ASKED: " << tostringRessources(*iter) << std::endl ;

        for(auto iter_b = pop_buy.begin() ; iter_b != pop_buy.end() ; ++iter_b){ // parcours les Ressourcess disponibles

            std::cout << "FOUND: " << tostringRessources(*iter_b) << " ; ";

            if(*iter_b == *iter){ // trouvé la bonne Ressources

                std::cout << " MATCH!" << std::endl;
                pop_buy.erase(iter_b);
                break;

            } else if(next(iter_b) == pop_buy.end()){ // on atteint la fin sans trouver de Ressources match : Ressources manquante

                std::cout << "NOT FOUND!" << std::endl;
                return false;
            }

        }
        std::cout << std::endl ;
    }
    return true ; // remove
}

std::ostream& operator<<(std::ostream& f, Carte c){
    f << c.getNom() << ", " << tostringType(c.getType()) << std::endl ;
    f << "COUT ARGENT: " << c.getCoutArgent() << std::endl ;
    f << "COUT RESSOURCES: " ;
    std::list<Ressources> res(c.getCoutRessource());
    for(auto iter = res.begin() ; iter != res.end() ; ++iter) { f << tostringRessources(*iter) << " ; " ; }
    f << std::endl ;
    f << "REWARDS: " << c.getRewardArgent() << " pièces ; " << c.getPointVictoire() << " points victoire" << std::endl ;
    return f ;
}

Merveille::Merveille(std::string nom, Types type, std::list<Ressources> cost_r, unsigned int cost_m, unsigned int argent, unsigned int pt_victoire, bool b) : Carte(nom, type, cost_r, cost_m, argent, pt_victoire), replay(b) {
    if(type!=Types::Merveille){
        throw GameException("Merveille instanciée avec un type autre que Merveille");
    }
};

Batiment::Batiment(std::string nom, Types type, std::list<Ressources> cost_r, unsigned int cost_m, unsigned int argent, unsigned int pt_victoire, std::list<Ressources> production, std::string chained_by):
        Carte(nom, type, cost_r, cost_m, argent, pt_victoire), chained_by(chained_by){
    // vérifications liées au type :
    if(type == Types::Civil && !production.empty()){
        throw GameException("ERREUR (Batiment instancié) : un bâtiment CIVIL ne produit pas de Ressourcess");
    }
    if(type == Types::Scientifique){
        if(!checkTypeRessources(production, getSymboleScientifique())){throw GameException("ERREUR (Batiment instancié) : un bâtiment SCIENTIFIQUE ne produit que des symboles scientifiques");}
        if(production.size() != 1){throw GameException("ERREUR (Batiment instancié) : un bâtiment SCIENTIFIQUE ne produit qu'un seul symbole");}
    }
    if(type == Types::Militaire){
        if(!checkTypeRessources(production, {Ressources::Bouclier})){throw GameException("ERREUR (Batiment instancié) : un bâtiment MILITAIRE ne produit que des boucliers");}
    }
    if(type == Types::Manufacture){
        if(!checkTypeRessources(production, getProduitManufacture())){throw GameException("ERREUR (Batiment instancié) : un bâtiment de Ressourcess GRIS ne produit que des produits manufacturés");}
    }
    if(type == Types::Premiere){
        if(!checkTypeRessources(production, getMatierePremiere())){throw GameException("ERREUR (Batiment instancié) : un bâtiment de Ressourcess MARRON ne produit que des matièrs premières");}

    }
}
