#include "wonders.h"

std::set<ressource> getMatierePremiere() {
    return {
        ressource::Pierre,
        ressource::Argile,
        ressource::Bois
    };
}

std::set<ressource> getProduitManufacture() {
    return {
        ressource::Papyrus,
        ressource::Verre
    };
}

std::set<ressource> getRessource() {
    return {
        ressource::Pierre,
        ressource::Argile,
        ressource::Bois,
        ressource::Papyrus,
        ressource::Verre
    };
}

std::set<ressource> getSymboleScientifique() {
    return {
        ressource::Roue,
        ressource::Compas,
        ressource::Pilon,
        ressource::Tablette,
        ressource::Lyre,
        ressource::Mesure,
        ressource::Telescope
    };
}

std::string tostringRessources(ressource r){
    switch(r) {
        case ressource::Roue : return "Roue" ;
        case ressource::Compas : return "Compas" ;
        case ressource::Pilon : return "Pilon" ;
        case ressource::Tablette : return "Tablette" ;
        case ressource::Lyre : return "Lyre" ;
        case ressource::Mesure : return "Mesure" ;
        case ressource::Telescope : return "Telescope" ;
        case ressource::Bouclier : return "Bouclier" ;
        case ressource::Papyrus : return "Papyrus" ;
        case ressource::Verre : return "Verre" ;
        case ressource::Pierre : return "Pierre" ;
        case ressource::Argile : return "Argile" ;
        case ressource::Bois : return "Bois" ;
        default : throw GameException("Ressource inconnue") ;
    };
}

std::string tostringType(type_batiment t){
    switch(t){
        case type_batiment::Civil : return "Civil" ;
        case type_batiment::Militaire : return "Civil" ;
        case type_batiment::Scientifique : return "Civil" ;
        case type_batiment::Manufacture : return "Civil" ;
        case type_batiment::Premiere : return "Civil" ;
        case type_batiment::Commerce : return "Civil" ;
        case type_batiment::Guilde : return "Civil" ;
        case type_batiment::Merveille : return "Civil" ;
        default : throw GameException("Batiment inconnue") ;
    };
}


bool Carte::checkCoutRessources(std::list<ressource> cost_r) const {
    std::set<ressource> standard_ressources = getRessource();
    for(auto iter = cost_r.begin() ; iter != cost_r.end() ; ++iter ) { // list iterator
        if( standard_ressources.find(*iter) == standard_ressources.end() ) {
            //std::cout << "WARNING : INVALID RESSOURCE LIST" << std::endl ;
            return false ;
        }
    }
    //std::cout << "CORRECT RESSOURCE LIST" << std::endl ;
    return true ;
}

Carte::Carte(std::string n, type_batiment t, std::list<ressource> c_r, unsigned int c_m, unsigned int arge, unsigned int vic, bool v){
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
    v = false;
}

void Carte::setCoutRessource(std::list<ressource> cost){
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
    std::list<ressource> res = c.getCoutRessource();
    for(auto iter = res.begin() ; iter != res.end() ; ++iter) { f << tostringRessources(*iter) << " ; " ; }
    f << std::endl ;
    f << "REWARDS: " << c.getRewardArgent() << " pièces ; " << c.getPointVictoire() << " points victoire" << std::endl ;
    return f ;
}
