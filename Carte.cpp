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



bool Carte::checkTypeRessourcess(std::list<Ressources> cost_r, std::set<Ressources> subset) const {
    //std::set<Ressources> standard_Ressourcess = getRessources(); 
    for(auto iter = cost_r.begin() ; iter != cost_r.end() ; ++iter ) { // list iterator 
        if( subset.find(*iter) == subset.end() ) {
            //std::cout << "WARNING : INVALID Ressources LIST" << std::endl ;
            return false ; 
        }
    }
    //std::cout << "CORRECT Ressources LIST" << std::endl ;
    return true ; 
} 

Carte::Carte(std::string n, Types t,  phase_jeu a, std::list<Ressources> c_r, unsigned int c_m, unsigned int arge, unsigned int vic):nom(n), type(t), c_age(a), argent(arge), pt_victoire(vic){

    if(c_r.size() > 5){
        throw GameException("ERREUR : trop de Ressourcess dans le coût de la carte instanciée") ; 
    }

    cost_m = c_m ; 
    
    if(!checkTypeRessourcess(c_r, getRessources())){
        throw GameException("ERREUR : list de Ressourcess invalide dans la carte instanciée (matières premières ou produits manufacturés SEULEMENT)") ;
    } 
    cost_r = c_r ;
}

void Carte::setCoutRessources(std::list<Ressources> cost){
    if(checkTypeRessourcess(cost, getRessources()) && cost.size() <= 5) {
        cost_r = cost ; 
    } else {
        throw GameException("ERREUR : list de Ressourcess invalide dans la carte à modifier (matières premières ou produits manufacturés SEULEMENT)") ;
    }
}

std::ostream& operator<<(std::ostream& f, const Carte& c){
    c.affichage();
    return f ; 
}

Batiment::Batiment(std::string nom, Types type, phase_jeu age, std::list<Ressources> cost_r, unsigned int cost_m, unsigned int argent, unsigned int pt_victoire, std::list<Ressources> prod, std::string chained_by):
Carte(nom, type, age, cost_r, cost_m, argent, pt_victoire), chained_by(chained_by){
    // vérifications liées au type : 
    if(type == Types::Civil && !production.empty()){
        throw GameException("ERREUR (Batiment instancié) : un bâtiment CIVIL ne produit pas de Ressourcess");
    }
    if(type == Types::Scientifique){
        if(!checkTypeRessourcess(prod, getSymboleScientifique())){throw GameException("ERREUR (Batiment instancié) : un bâtiment SCIENTIFIQUE ne produit que des symboles scientifiques");}
        if(prod.size() != 1){throw GameException("ERREUR (Batiment instancié) : un bâtiment SCIENTIFIQUE ne produit qu'un seul symbole");}
    }
    if(type == Types::Militaire){
        if(!checkTypeRessourcess(prod, {Ressources::Bouclier})){throw GameException("ERREUR (Batiment instancié) : un bâtiment MILITAIRE ne produit que des boucliers");}
    }
    if(type == Types::Manufacture){
        if(!checkTypeRessourcess(prod, getProduitManufacture())){throw GameException("ERREUR (Batiment instancié) : un bâtiment de Ressourcess GRIS ne produit que des produits manufacturés");}
    }
    if(type == Types::Premiere){
        if(!checkTypeRessourcess(prod, getMatierePremiere())){throw GameException("ERREUR (Batiment instancié) : un bâtiment de Ressourcess MARRON ne produit que des matièrs premières");}

    }

    production = prod ; 
}

void Carte::affichage() const {
    std::cout << nom << ", " << tostringType(type) << ", " << tostringAge(c_age) << std::endl ; 
    std::cout << "COUT ARGENT: " << cost_m << std::endl ;
    std::cout << "COUT RessourcesS: " ;
    std::list<Ressources> res(getCoutRessources());
    for(auto iter = res.begin() ; iter != res.end() ; ++iter) { std::cout << tostringRessourcess(*iter) << " ; " ; }
    std::cout << std::endl ;
    std::cout << "REWARDS: " << argent << " pièces ; " << pt_victoire << " points victoire" << std::endl ;
}

void Batiment::affichage() const {
    Carte::affichage();
    std::cout << "PRODUCTION: " ;
    displayRessourcess( production ) ;
}

void Batiment::onBuild(Joueur* j) const {
    std::cout << "CALLING ONBUILD BATIMENT" << std::endl ;
    return ; 
}

Commerce::Commerce(
    std::string nom, Types type, phase_jeu age, 
    std::list<Ressources> cost_r, unsigned int cost, 
    unsigned int argent, unsigned int pt_victoire, std::list<Ressources> prod, 
    std::string chained_by, const Perk* perk):
        Batiment(nom, type,age, cost_r, cost, argent, pt_victoire, prod, chained_by), perk(perk) {

            if( type != Types::Commerce && type != Types::Merveille ){ throw GameException("ERREUR : instanciation d'un bâtiment non Commerce avec la classe Commerce");}
            // comme le constructeur de Commerce est appelé pour construire Merveille
            // we need to allow the Commerce constructor to create Merveille types

}

Commerce::~Commerce() { if(perk!=nullptr){delete perk ;} }

void Commerce::onBuild(Joueur* j) const {
    std::cout << "CALLING ONBUILD COMMERCE" << std::endl ;
    if(perk!=nullptr){
        perk->onCall(j); 
    }
}

/*
void Merveille::onBuild(Joueur* j) const {

}
*/

Guilde::Guilde(
    std::string nom, Types type, phase_jeu age,
    std::list<Ressources> cost_r, unsigned int cost,
    unsigned int argent, unsigned int pt_victoire,

    std::list<Types> affectation, bool usurier):
    Carte(nom, type, age,cost_r, cost, argent, pt_victoire),affectation(affectation), usurier(usurier){
        if( type != Types::Guilde ){ throw GameException("ERREUR: Utilisation du constructeur de Guilde avec un Types invalide");}
}

unsigned int Guilde::ptVictoireFinJeu(Joueur* j) const {

    /*
    if( usurier ){ return std::max(j->getTresor()/3, j->getAdversaire()->getTresor()/3) ;}

    unsigned int p[2] = {0, 0} ;
    Joueur* jp[2] = {j, j->getAdversaire()};

    for(size_t i = 0 ; i < 1 ; i++){
        for( auto iter = affectation.begin() ; iter != affectation.end() ; ++iter ){
            p[i] += jp[i]->getNumberBatiment(*iter);
        }
    }

    return std::max(p[0], p[1]) ;
    */
    return 0 ; // TEMP

}

void Guilde::rewardArgent(Joueur* j) const {

    /*
    unsigned int p[2] = {0, 0} ;
    Joueur* jp[2] = {j, j->getAdversaire()};

    for(size_t i = 0 ; i < 1 ; i++){
        for( auto iter = affectation.begin() ; iter != affectation.end() ; ++iter ){
            p[i] += jp[i]->getNumberBatiment(*iter) * getRewardArgent() ;
        }
    }

    j->addTresor( std::max(p[0], p[1]) );
    */
}

void Guilde::onBuild(Joueur* j) const {
    std::cout << "CALLING ONBUILD GUILDE" << std::endl ;
    //rewardArgent(j);
}

void Perk_CoinPerCard::gainCoinPerCard(Joueur* j) const {
    //j->addTresor( j->getNumberBatiment(this->card)*coin );
}

void Perk_CoinPerCard::onCall(Joueur* j) const {
    //gainCoinPerCard(j);
}

void Perk_FixedTrade::setFixedTrade(Joueur* j) const {/*
    for(auto iter = res.begin() ; iter != res.end() ; ++iter){
        j->setFixedTrade(*iter, coin);
    }
    */
}

void Perk_FixedTrade::onCall(Joueur* j) const {
    setFixedTrade(j);
}

Perk_Classic::Perk_Classic(unsigned int id, const GameManager* box):id(id), box(box){
    if(id > 2){
        throw GameException("ERREUR: Classic Perk id is 0 - 1 - 2");
    }
    if(box == nullptr){
        throw GameException("ERREUR: Un pointeur vers Box non nul est requis pour une Perk Classic");
    }
}

void Perk_Classic::saccage(Joueur* j) const {
    //j->getAdversaire()->subTresor(3);
}

void Perk_Classic::freeConstructionFromDefausse(Joueur* j) const { 
    // requires player interaction
}

void Perk_Classic::pickJeton(Joueur* j) const { 
    // requires player interaction
}

void Perk_Classic::onCall(Joueur* j) const {
    switch(id){
        case 0 : /*saccage(j) ;*/ break ;
        case 1 : /*pickJeton(j) ;*/ break ; 
        case 2 : /*freeConstructionFromDefausse(j) ;*/ break ; 
        default : throw GameException("ERREUR: unknown Classic Perk id") ; 
    }
}

Perk_Destruction::Perk_Destruction(type_batiment c):card(c){
    if(c != type_batiment::Premiere || c != type_batiment::Manufacture){
        throw GameException("ERREUR: La destruction par Perk Destruction n'est permise que sur Batiment Premiere ou Manufacture");
    }
}

void Perk_Destruction::destruction(Joueur* j) const {
    // requires player interaction
}

void Perk_Destruction::onCall(Joueur* j) const {
    // destruction(j);
}
