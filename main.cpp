#include "joueur.h"

int main() {
    Ressources ressourcesJoueur[] = {bois, bois, pierre};
    Symboles_Progres symbolesProgresJoueur[] = {philosophie, economie};

    Joueur joueur1(1, ressourcesJoueur, symbolesProgresJoueur, 3, 2);

    // Obtenir l'ID du joueur
    cout << "ID du joueur : " << joueur1.getIdJoueur() << endl;

    // Obtenir les ressources du joueur
    cout << "Ressources du joueur : ";
    const Ressources* ressources = joueur1.getRessources();
    for (int i = 0; i < joueur1.getIdJoueur(); ++i) {
        cout << ressources[i] << " ";
    }
    cout << endl;

    // Obtenir les symboles de progrès du joueur
    cout << "Symboles de progrès du joueur : ";
    const Symboles_Progres* symbolesProgres = joueur1.getSymbolesProgres();
    for (int i = 0; i < joueur1.getIdJoueur(); ++i) {
        cout << symbolesProgres[i] << " ";
    }
    cout << endl;

    // Ajouter une nouvelle ressource
    joueur1.ajouterRessource(argile);

    // Ajouter un nouveau symbole de progrès
    joueur1.ajouterSymboleProgres(theologie);

    // Afficher les ressources mises à jour
    cout << "Ressources mises à jour du joueur : ";
    ressources = joueur1.getRessources();
    for (int i = 0; i < joueur1.getIdJoueur(); ++i) {
        cout << ressources[i] << " ";
    }
    cout << endl;

    // Afficher les symboles de progrès mis à jour
    cout << "Symboles de progrès mis à jour du joueur : ";
    symbolesProgres = joueur1.getSymbolesProgres();
    for (int i = 0; i < joueur1.getIdJoueur(); ++i) {
        cout << symbolesProgres[i] << " ";
    }
    cout << endl;

    return 0;
}
