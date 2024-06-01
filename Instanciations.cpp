#include <iostream>
#include "GameManager.h"

// Test de la construction  d'un batiment
        Batiment chantier = Batiment(
                "Chantier", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bois}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment exploitation = Batiment(
                "Exploitation", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                1, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bois}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment bassin_argileux = Batiment(
                "Bassin argileux", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Argile}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment cavite = Batiment(
                "Cavite", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                1, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Argile}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment gisement = Batiment(
                "Gisement", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Pierre}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment mine = Batiment(
                "Mine", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                1, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Pierre}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment verrerie = Batiment(
                "Verrerie", // Nom du bâtiment
                Types::Manufacture, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                1, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Verre}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment presse = Batiment(
                "Presse", // Nom du bâtiment
                Types::Manufacture, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                1, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Verre}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment Tour_de_garde = Batiment(
                "Tour de garde", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment Atelier = Batiment(
                "Atelier", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {Ressources::Papyrus}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                1, // Points de victoire
                {Ressources::Compas}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment apothicaire = Batiment(
                "apothicaire", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {Ressources::Verre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                1, // Points de victoire
                {Ressources::Roue}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );




        Batiment Ecuries = Batiment(
                "Ecuries", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {Ressources::Bois}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment caserne = Batiment(
                "Caserne", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {Ressources::Argile}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment Palissade = Batiment(
                "Palissade", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                2, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment scriptorium = Batiment(
                "Scriptorium", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                2, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Plume}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment officine = Batiment(
                "Officine", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                2, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Pilon}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment theatre = Batiment(
                "Theatre", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                3, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment autel = Batiment(
                "Autel", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                3, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );


        Batiment bains = Batiment(
                "Bains", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_I, // âge de la carte
                {Ressources::Pierre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                3, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment scierie = Batiment(
                "Scierie", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {}, // Liste des ressources nécessaires
                2, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bois,Ressources::Bois}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment briqueterie = Batiment(
                "Briqueterie", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {}, // Liste des ressources nécessaires
                2, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Argile,Ressources::Argile}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment carriere = Batiment(
                "Carriere", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {}, // Liste des ressources nécessaires
                2, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Pierre,Ressources::Pierre}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment soufflerie = Batiment(
                "Soufflerie", // Nom du bâtiment
                Types::Manufacture, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Verre}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment sechoir = Batiment(
                "Sechoir", // Nom du bâtiment
                Types::Manufacture, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Papyrus}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment muraille = Batiment(
                "Muraille", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Pierre, Ressources::Pierre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment tribunal = Batiment(
                "Tribunal", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Bois, Ressources::Bois, Ressources::Verre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                5, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment haras = Batiment(
                "Haras", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Argile, Ressources::Bois}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "Ecuries" // Bâtiment chaîné (si applicable)
        );

        Batiment baraquements = Batiment(
                "Baraquements", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {}, // Liste des ressources nécessaires
                3, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "Caserne" // Bâtiment chaîné (si applicable)
        );

        Batiment champ_de_tir = Batiment(
                "Champ de tir", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Pierre, Ressources::Bois, Ressources::Papyrus}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment place_d_armes = Batiment(
                "Place d'arme", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Verre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment bibliotheque = Batiment(
                "Bibliotheque", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Pierre, Ressources::Bois, Ressources::Verre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                2, // Points de victoire
                {Ressources::Plume}, // Liste des ressources produites par le bâtiment
                "Scriptorium" // Bâtiment chaîné (si applicable)
        );

        Batiment dispensaire = Batiment(
                "Dispensaire", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Pierre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                2, // Points de victoire
                {Ressources::Pilon}, // Liste des ressources produites par le bâtiment
                "Officine" // Bâtiment chaîné (si applicable)
        );

        Batiment ecole = Batiment(
                "Ecole", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Bois, Ressources::Papyrus, Ressources::Papyrus}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                1, // Points de victoire
                {Ressources::Roue}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment laboratoire = Batiment(
                "Laboratoire", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Bois, Ressources::Verre, Ressources::Verre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                1, // Points de victoire
                {Ressources::Compas}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment statue = Batiment(
                "Statue", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Argile, Ressources::Argile}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                4, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "Theatre" // Bâtiment chaîné (si applicable)
        );

        Batiment temple = Batiment(
                "Temple", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Bois, Ressources::Papyrus}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                4, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "Autel" // Bâtiment chaîné (si applicable)
        );

        Batiment aqueduc = Batiment(
                "Aqueduc", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Pierre, Ressources::Pierre, Ressources::Pierre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                5, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "Bains" // Bâtiment chaîné (si applicable)
        );

        Batiment rostres = Batiment(
                "Rostres", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_II, // âge de la carte
                {Ressources::Pierre, Ressources::Bois}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                4, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment arsenal = Batiment(
                "Arsenal", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Argile, Ressources::Bois, Ressources::Bois}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment pretoire = Batiment(
                "Pretoire", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {}, // Liste des ressources nécessaires
                8, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment academie = Batiment(
                "Academie", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Pierre, Ressources::Bois, Ressources::Verre, Ressources::Verre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                3, // Points de victoire
                {Ressources::Cadran}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment etude = Batiment(
                "Etude", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Bois, Ressources::Bois, Ressources::Verre, Ressources::Papyrus}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                3, // Points de victoire
                {Ressources::Cadran}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment palace = Batiment(
                "Palace", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Argile, Ressources::Pierre, Ressources::Bois, Ressources::Verre, Ressources::Verre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                7, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment hotel_de_ville = Batiment(
                "Hotel de ville", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Pierre, Ressources::Pierre, Ressources::Pierre, Ressources::Bois, Ressources::Bois}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                7, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment obelisque = Batiment(
                "Obelisque", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Pierre, Ressources::Pierre, Ressources::Verre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                5, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment fortifications = Batiment(
                "Fortifications", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Pierre, Ressources::Pierre, Ressources::Argile, Ressources::Papyrus}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "Palissade" // Bâtiment chaîné (si applicable)
        );

        Batiment atelier_de_siege = Batiment(
                "Atelier de siege", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Bois, Ressources::Bois, Ressources::Bois, Ressources::Verre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "Champ de tir" // Bâtiment chaîné (si applicable)
        );

        Batiment crique = Batiment(
                "Cirque", // Nom du bâtiment
                Types::Militaire, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Pierre, Ressources::Pierre}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le bâtiment
                "Place d'arme" // Bâtiment chaîné (si applicable)
        );

        Batiment universite = Batiment(
                "Universite", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Argile, Ressources::Verre, Ressources::Papyrus}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                2, // Points de victoire
                {Ressources::Telescope}, // Liste des ressources produites par le bâtiment
                "Ecole" // Bâtiment chaîné (si applicable)
        );

        Batiment observatoire = Batiment(
                "Observatoire", // Nom du bâtiment
                Types::Scientifique, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Pierre, Ressources::Papyrus, Ressources::Papyrus}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                2, // Points de victoire
                {Ressources::Telescope}, // Liste des ressources produites par le bâtiment
                "Laboratoire" // Bâtiment chaîné (si applicable)
        );

        Batiment jardins = Batiment(
                "Jardins", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Bois, Ressources::Bois}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                6, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "Statue" // Bâtiment chaîné (si applicable)
        );

        Batiment pantheon = Batiment(
                "Pantheon", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Argile, Ressources::Bois, Ressources::Papyrus, Ressources::Papyrus}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                6, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "Temple" // Bâtiment chaîné (si applicable)
        );

        Batiment senat = Batiment(
                "Senat", // Nom du bâtiment
                Types::Civil, // Type du bâtiment
                phase_jeu::AGE_III, // âge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Pierre, Ressources::Papyrus}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                5, // Points de victoire
                {}, // Liste des ressources produites par le bâtiment
                "Rostres" // Bâtiment chaîné (si applicable)
        );
