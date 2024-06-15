#include "wonders.h"



void Layout::displayLayout() const {
   

    size_t rows = age.size() ;
    size_t columns = age[0].size();
    int s = rows ;

    for(int i = 0 ; i < rows ; i++){
        std::cout << std::string(2 * s, ' ');
        bool show = false;
        for(int j= 0 ; j < columns ; j++){
            if( age[i][j] != 0 && age[i][j] != 4){
                std::cout << " | " << age[i][j] ;
                show = true;
            } else {
                if (show){
                    std::cout << " | ";
                }
                std::cout << "    " ;
                show = false;
            }
        }
        if (show){
            std::cout << " | ";
        }
        std::cout << std::endl ;
        s--;
    }
}


void Layout::switchAge(phase_jeu p){

    cards.clear();

    switch(p){
        case phase_jeu::AGE_I :
            age = ageI ;
            break ;
        case phase_jeu::AGE_II :
            age = ageII ;
            break ;
        case phase_jeu::AGE_III :
            age = ageIII ;
            break ;
        case phase_jeu::START :
            age.clear();
            break ;
        case phase_jeu::END :
            age.clear();
            break ;
        default :
            throw GameException("AGE INCONNU") ;
    };
}

void Layout::updateLayout(){
    size_t rows = age.size();
    size_t columns = age[0].size() ;

    for(int i = 0 ; i < rows-1 ; i++){ // on ne va pas sur la dernière rangée, toujours accessibles
        for(int j=0 ; j < columns ; j++){

            //std::cout << "reading : " << age[i][j] << " | " << age[i+1][j] << " | " << age[i+1][j+1] << std::endl ;
            if(j == columns -1){
                if( ((age[i][j] != 0) && (age[i][j] != 4)) && ((age[i+1][j] == 0)||(age[i+1][j] == 4)) ){ // on ne check que la carte du dessous pour les cartes les plus à droite
                    age[i][j] = 1 ; // visible et accessible
                }
            } else {

                if( ((age[i][j] != 0)&&(age[i][j] != 4)) && ((age[i+1][j] == 0)||(age[i+1][j] == 4)) && ((age[i+1][j+1] == 0)||(age[i+1][j+1] == 4)) ){ // les deux cartes qui recouvrent ont disparues
                    age[i][j] = 1 ; // visible et accessible
                }
            }

        }
    }
}

bool Layout::isEmpty() const {
    for(auto iter_rows = age.begin() ; iter_rows != age.end() ; ++iter_rows){
        for(auto iter_columns = iter_rows->begin() ; iter_columns != iter_rows->end() ; ++iter_columns){

            if( *iter_columns != 0 && *iter_columns != 4 ){
                return false ;
            }

        }
    }
    return true ;
}

unsigned int Layout::getLayoutSize() const { // retourne le nombre de non 0 dans la matrice

    unsigned int size = 0 ;

    for(auto iter_rows = age.begin() ; iter_rows != age.end() ; ++iter_rows){
        for(auto iter_columns = iter_rows->begin() ; iter_columns != iter_rows->end() ; ++iter_columns){
            if( *iter_columns != 0 && *iter_columns != 4 ){ size ++ ;}
        }
    }

    return size ;

}

unsigned int Layout::getVectorSize() const { // retourne le nombre d'éléments non nullptr dans cards

    unsigned int x = 0 ;
    for( auto iter = cards.begin() ; iter != cards.end() ; ++iter ){
        if( *iter != nullptr ){ x++ ;}
    }

    return x ;

}


void Layout::inputCards(std::vector<const Carte*> deck){

    // ajoute seulement des cartes 
    // pas de shuffle, c'est Box qui s'en occupe

    for(auto iter = deck.begin() ; iter != deck.end() ; ++iter){
        cards.push_back(*iter);
    }

    return ;

}

void Layout::reinit(){
    cards.clear();
    age = ageI ;
}

// NEW ARCHITECTURE OF THE LAYOUT (guaranteed not to be a mess by yours truly)

std::vector<int> Layout::unroll() const {

    checkMatching();
    std::vector<int> one_dim;

    for( auto iter_rows = age.begin() ; iter_rows != age.end() ; ++iter_rows){
        for( auto iter_columns = (*iter_rows).begin() ; iter_columns != (*iter_rows).end() ; ++iter_columns ){
            if (*iter_columns != 0){ one_dim.push_back(*iter_columns); }
        }
    }
    return one_dim ;

}

unsigned int Layout::coordsToIndex(unsigned int x, unsigned int y) const {

    unsigned int index = 0 ;

    for( size_t iter_rows = 0 ; iter_rows < age.size() ; ++iter_rows){
        for( size_t iter_columns = 0 ; iter_columns < age[iter_rows].size() ; ++iter_columns ){

            if( age[iter_rows][iter_columns] != 0 ){

                if(iter_rows == x && iter_columns == y){
                    return index ;
                }

                index ++ ;
            }
        }
    }
    throw GameException("ERREUR: error converting coords to index (Layout)");
}

std::pair<unsigned int, unsigned int> Layout::indexToCoords(unsigned int i) const {

    unsigned int index = 0 ;

    for( size_t iter_rows = 0 ; iter_rows < age.size() ; ++iter_rows){
        for( size_t iter_columns = 0 ; iter_columns < age[iter_rows].size() ; ++iter_columns ){

            if( age[iter_rows][iter_columns] != 0 ){
                if( index == i){
                    return std::make_pair(iter_rows, iter_columns);
                }
                index ++ ;
            }

        }
    }

    throw GameException("ERREUR: error during conversion from coords to index (Layout)");
}

unsigned int Layout::availableToAll(unsigned int index) const {
    unsigned int available_index = 0 ;
    std::vector<int> one_dim = unroll() ;
    for(size_t i = 0 ; i < one_dim.size() ; i++){

        if(one_dim[i] == 1){
            if(index == available_index){
                return i;
            }
            available_index ++ ;
        }
    }
    throw GameException("ERREUR: error during conversion from available index to global index (Layout)");
}


std::vector<const Carte*> Layout::getVisibleCards(bool available_only) const {

    std::vector<int> one_dim = unroll();
    std::vector<const Carte*> visible ;

    for( size_t i = 0 ; i < one_dim.size() ; i++){

        if(one_dim[i] == 1 || (one_dim[i] == 1 && !available_only)){
            visible.push_back( cards[i] );
        }

    }
    return visible ;
}

const Carte& Layout::removeCard(unsigned int x, unsigned int y){
    if( age[x][y] != 1 ){
        throw GameException("ERREUR: La Carte demandée dans Layout n'est pas accessible");
    }
    age[x][y] = 4 ;
    const Carte& save = *cards[ coordsToIndex(x, y) ];
    cards[ coordsToIndex(x, y) ] = nullptr ;
    updateLayout();
    return save;
}

const Carte& Layout::removeCard(unsigned int i){
    return removeCard( indexToCoords(i).first, indexToCoords(i).second );
}

const Carte& Layout::seeCard(unsigned int x, unsigned int y) const {
    if( age[x][y] != 1 || age[x][y] != 2 ){
        throw GameException("ERREUR: La Carte demandée dans Layout n'est pas visible");
    }
    return *cards[ coordsToIndex(x, y) ] ;
}

const Carte& Layout::seeCard(unsigned int i) const {
    return seeCard( indexToCoords(i).first, indexToCoords(i).second );
}