#ifndef INC_7_WONDERS_TYPE_H
#define INC_7_WONDERS_TYPE_H

enum Batiments {Commerce, Scientifique, Premiere, Manufacture, Militaire, Guilde, Merveille}
// On retire Guilde et Merveille ou pas ??

enum Ressources { bois, argile, pierre };

enum class JetonsProgres{
    Agriculture, Architecture, Economie, Loi, Maconnerie, Mathematiques,
    Philosophie, Strategie, Theologie, Urbanisme
};

enum class SymboleScientifiques{
    Roue, Compas, Mortier_Pilon, Tablette, Lyre, Mesure, Telescope
};
enum class produitManufacture{
    Verre, Papyrus
};
#endif //INC_7_WONDERS_TYPE_H
