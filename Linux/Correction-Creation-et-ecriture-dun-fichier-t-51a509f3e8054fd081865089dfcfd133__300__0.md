# Correction - Création et écriture d’un fichier texte

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string texte;

    // Demander à l'utilisateur de saisir un texte
    std::cout << "Saisissez un texte : ";
    std::getline(std::cin, texte);

    // Écrire le texte dans un fichier
    std::ofstream fichierSortie("mon_texte.txt");

    if (fichierSortie.is_open()) {
        fichierSortie << texte;
        fichierSortie.close();
        std::cout << "Le texte a été enregistré avec succès dans 'mon_texte.txt'." << std::endl;
    } else {
        std::cout << "Erreur lors de l'ouverture du fichier pour l'écriture." << std::endl;
        return 1; // Quitter le programme en cas d'erreur
    }

    // Demander à l'utilisateur s'il souhaite lire le contenu du fichier
    char reponse;
    std::cout << "Voulez-vous lire le contenu du fichier ? (o/n) : ";
    std::cin >> reponse;

    if (reponse == 'o' || reponse == 'O') {
        std::ifstream fichierEntree("mon_texte.txt");

        if (fichierEntree.is_open()) {
            std::string contenu;
            while (std::getline(fichierEntree, contenu)) {
                std::cout << contenu << std::endl;
            }
            fichierEntree.close();
        } else {
            std::cout << "Erreur lors de l'ouverture du fichier pour la lecture." << std::endl;
            return 1; // Quitter le programme en cas d'erreur
        }
    } else {
        std::cout << "Fin du programme." << std::endl;
    }

    return 0;
}
```