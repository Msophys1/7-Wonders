#include "wonders.h"

#include <set>

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

Carte::Carte(std::string n, type_batiment t, std::list<ressource> c_r, unsigned int c_m, unsigned int arge, unsigned int vic){
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

void Carte::setCoutRessource(std::list<ressource> cost){
    if(checkCoutRessources(cost) && cost.size() <= 5) {
        cost_r = cost ; 
    } else {
        throw GameException("ERREUR : list de ressources invalide dans la carte à modifier (matières premières ou produits manufacturés SEULEMENT)") ;
    }
}    

