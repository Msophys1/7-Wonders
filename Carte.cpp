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
        case Types::Militaire : return "Civil" ;
        case Types::Scientifique : return "Civil" ;
        case Types::Manufacture : return "Civil" ;
        case Types::Premiere : return "Civil" ;
        case Types::Commerce : return "Civil" ;
        case Types::Guilde : return "Civil" ;
        case Types::Merveille : return "Civil" ;
        default : throw GameException("Batiment inconnue") ;
    };
}


bool Carte::checkCoutRessources(std::list<Ressources> cost_r) const {
    std::set<Ressources> standard_ressources = getRessource();
    for(auto iter = cost_r.begin() ; iter != cost_r.end() ; ++iter ) { // list iterator
        if( standard_ressources.find(*iter) == standard_ressources.end() ) {
            //std::cout << "WARNING : INVALID RESSOURCE LIST" << std::endl ;
            return false ;
        }
    }
    //std::cout << "CORRECT RESSOURCE LIST" << std::endl ;
    return true ;
}

Carte::Carte(std::string n, Types t, std::list<Ressources> c_r, unsigned int c_m, unsigned int arge, unsigned int vic){
    nom = n ;
    type = t ;

    if(c_r.size() > 5){
        throw GameException("ERREUR : trop de ressources dans le coût de la carte instanciée") ;
    }

    cost_m = c_m ;

    if(!checkCoutRessources(c_r)){
        throw GameException("ERREUR : list de ressources invalide dans la carte instanciée (matières premières ou produits manufacturés SEULEMENT)") ;
    }
    cost_r = c_r ;

    argent = arge ;
    pt_victoire = vic ;
}


void Carte::setCoutRessource(std::list<Ressources> cost){
    if(checkCoutRessources(cost) && cost.size() <= 5) {
        cost_r = cost ;
    } else {
        throw GameException("ERREUR : list de ressources invalide dans la carte à modifier (matières premières ou produits manufacturés SEULEMENT)") ;
    }
}

std::ostream& operator<<(std::ostream& f, Carte c){
    f << c.getNom() << std::endl ;
    f << "COUT ARGENT: " << c.getCoutArgent() << std::endl ;
    f << "COUT RESSOURCES: " ;
    std::list<Ressources> res = c.getCoutRessource();
    for(auto iter = res.begin() ; iter != res.end() ; ++iter) { f << tostringRessources(*iter) << " ; " ; }
    f << std::endl ;
    f << "REWARDS: " << c.getRewardArgent() << " pièces ; " << c.getPointVictoire() << " points victoire" << std::endl ;
    return f ;
}
