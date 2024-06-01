#include "Carte.h"

// UTILS 

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

std::set<Ressources> getRessources() {
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

std::string tostringRessourcess(Ressources r){
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
        default : throw GameException("Ressources inconnue") ;
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
        default : throw GameException("Batiment inconnu") ;
    };
}

std::string tostringJeton(jeton_progres j){
    switch(j){
        case jeton_progres::Architecture : return "Architecture" ;
        case jeton_progres::Economie : return "Economie" ; 
        case jeton_progres::Loi : return "Loi" ;
        case jeton_progres::Maconnerie : return "Maçonnerie" ;
        case jeton_progres::Mathematiques : return "Mathématiques" ;
        case jeton_progres::Philosophie : "Philosophie" ; 
        case jeton_progres::Strategie : return "Stratégie" ;
        case jeton_progres::Theologie : return "Théologie" ;
        case jeton_progres::Urbanisme : return "Urbanisme" ;
        default : throw GameException("Jeton inconnu");
    }
}

std::string tostringAge(phase_jeu p){
    switch(p){
        case phase_jeu::START : return "INIT" ; 
        case phase_jeu::AGE_I : return "AGE I" ; 
        case phase_jeu::AGE_II: return "AGE II" ; 
        case phase_jeu::AGE_III : return "AGE III" ; 
        case phase_jeu::END : return "FIN" ; 
        default : throw GameException("Age inconnu") ;
    }
}


phase_jeu& operator++(phase_jeu& phase){
    if( static_cast<int>(phase) != 4 ){
        phase = static_cast<phase_jeu>(static_cast<int>(phase)+1) ;
    } else {
        phase = static_cast<phase_jeu>(static_cast<int>(0));
    }
    return phase ; 
}

bool Carte::checkTypeRessourcesss(std::list<Ressourcess> cost_r, std::set<Ressourcess> subset) const {
    //std::set<Ressourcess> standard_Ressourcesss = getRessourcess(); 
    for(auto iter = cost_r.begin() ; iter != cost_r.end() ; ++iter ) { // list iterator 
        if( subset.find(*iter) == subset.end() ) {
            //std::cout << "WARNING : INVALID Ressourcess LIST" << std::endl ;
            return false ;
        }
    }
    //std::cout << "CORRECT Ressourcess LIST" << std::endl ;
    return true ; 
} 

Carte::Carte(std::string n, Types t,  phase_jeu a, std::list<Ressourcess> c_r, unsigned int c_m, unsigned int arge, unsigned int vic):nom(n), type(t), c_age(a), argent(arge), pt_victoire(vic){

    if(c_r.size() > 5){
        throw GameException("ERREUR : trop de Ressourcesss dans le coût de la carte instanciée") ; 
    }

    cost_m = c_m ; 
    
    if(!checkTypeRessourcesss(c_r, getRessourcess())){
        throw GameException("ERREUR : list de Ressourcesss invalide dans la carte instanciée (matières premières ou produits manufacturés SEULEMENT)") ;
    } 
    cost_r = c_r ;
}

void Carte::setCoutRessourcess(std::list<Ressourcess> cost){
    if(checkTypeRessourcesss(cost, getRessourcess()) && cost.size() <= 5) {
        cost_r = cost ; 
    } else {
        throw GameException("ERREUR : list de Ressourcesss invalide dans la carte à modifier (matières premières ou produits manufacturés SEULEMENT)") ;
    }
}

std::list<Ressourcess> Carte::achetableRessourcess(std::list<Ressourcess> buy) const {
    if(cost_r.empty()) { return {} ; }
    //if(cost_r.size() > buy.size()) { return false ; }

    std::list<Ressourcess> pop_buy = buy ; // pas forcément nécéssaire, à vérifier (on ne veut pas altérer la liste de Ressourcess donnée)
    std::list<Ressourcess> missing = {}; 
    
    for(auto iter = cost_r.begin() ; iter != cost_r.end() ; ++iter){ // parcours les Ressourcesss demandées
        std::cout << "ASKED: " << tostringRessourcesss(*iter) << std::endl ;
        
        for(auto iter_b = pop_buy.begin() ; iter_b != pop_buy.end() ; ++iter_b){ // parcours les Ressourcesss disponibles
            
            std::cout << "FOUND: " << tostringRessourcesss(*iter_b) << " ; ";

            if(*iter_b == *iter){ // bonne Ressourcess trouvée

                std::cout << " MATCH!" << std::endl;
                pop_buy.erase(iter_b);
                break;

            } else if(next(iter_b) == pop_buy.end()){ // on atteint la fin sans trouver de Ressourcess match : Ressourcess manquante

                std::cout << "NOT FOUND!" << std::endl;
                missing.push_back(*iter);
            }

        } 
        std::cout << std::endl ;
    }
    return missing ;
}

std::ostream& operator<<(std::ostream& f, Carte c){
    f << c.getNom() << ", " << tostringType(c.getType()) << ", " << tostringAge(c.getAge()) << std::endl ; 
    f << "COUT ARGENT: " << c.getCoutArgent() << std::endl ; 
    f << "COUT RessourcessS: " ;
    std::list<Ressourcess> res(c.getCoutRessourcess());
    for(auto iter = res.begin() ; iter != res.end() ; ++iter) { f << tostringRessourcesss(*iter) << " ; " ; }
    f << std::endl ;
    f << "REWARDS: " << c.getRewardArgent() << " pièces ; " << c.getPointVictoire() << " points victoire" << std::endl ;
    return f ; 
}

Batiment::Batiment(std::string nom, Types type, phase_jeu age, std::list<Ressourcess> cost_r, unsigned int cost_m, unsigned int argent, unsigned int pt_victoire, std::list<Ressourcess> prod, std::string chained_by):
Carte(nom, type, age, cost_r, cost_m, argent, pt_victoire), chained_by(chained_by){
    // vérifications liées au type : 
    if(type == Types::Civil && !production.empty()){
        throw GameException("ERREUR (Batiment instancié) : un bâtiment CIVIL ne produit pas de Ressourcesss");
    }
    if(type == Types::Scientifique){
        if(!checkTypeRessourcesss(prod, getSymboleScientifique())){throw GameException("ERREUR (Batiment instancié) : un bâtiment SCIENTIFIQUE ne produit que des symboles scientifiques");}
        if(prod.size() != 1){throw GameException("ERREUR (Batiment instancié) : un bâtiment SCIENTIFIQUE ne produit qu'un seul symbole");}
    }
    if(type == Types::Militaire){
        if(!checkTypeRessourcesss(prod, {Ressourcess::Bouclier})){throw GameException("ERREUR (Batiment instancié) : un bâtiment MILITAIRE ne produit que des boucliers");}
    }
    if(type == Types::Manufacture){
        if(!checkTypeRessourcesss(prod, getProduitManufacture())){throw GameException("ERREUR (Batiment instancié) : un bâtiment de Ressourcesss GRIS ne produit que des produits manufacturés");}
    }
    if(type == Types::Premiere){
        if(!checkTypeRessourcesss(prod, getMatierePremiere())){throw GameException("ERREUR (Batiment instancié) : un bâtiment de Ressourcesss MARRON ne produit que des matièrs premières");}

    }

    production = prod ; 
}
