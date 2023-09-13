# Correction - Fonctions sur chaînes de caractères

```cpp
#include <iostream>
#include <string>

int main() {
    // Demande à l'utilisateur d'entrer deux chaînes de caractères (de type string).
    std::string chaine1, chaine2;
    std::cout << "Entrez la première chaîne de caractères: ";
    std::cin >> chaine1;
    std::cout << "Entrez la deuxième chaîne de caractères: ";
    std::cin >> chaine2;

    // Utilisez la méthode length() pour afficher la longueur de chaque chaîne de caractères saisie par l'utilisateur.
    std::cout << "La longueur de la première chaîne est: " << chaine1.length() << std::endl;
    std::cout << "La longueur de la deuxième chaîne est: " << chaine2.length() << std::endl;

    // Utilisez la méthode size() pour vérifier si les deux chaînes ont la même longueur et affichez un message approprié.
    if (chaine1.size() == chaine2.size()) {
        std::cout << "Les deux chaînes ont la même longueur." << std::endl;
    } else {
        std::cout << "Les deux chaînes n'ont pas la même longueur." << std::endl;
    }

    // Utilisez l'opérateur [] pour sélectionner le premier et le dernier caractère de chaque chaîne et affichez-les.
    std::cout << "Les premiers et derniers caractères des chaînes sont: " << chaine1[0] << chaine1[chaine1.size()-1] << " et " << chaine2[0] << chaine2[chaine2.size()-1] << std::endl;

    // Utilisez la méthode at() pour afficher le caractère situé à la position n/2 (n étant la longueur de la chaîne) pour chaque chaîne de caractères.
    std::cout << "Les caractères situés à la position n/2 pour chaque chaîne sont: " << chaine1.at(chaine1.size()/2) << " et " << chaine2.at(chaine2.size()/2) << std::endl;

    // Demandez à l'utilisateur d'entrer une sous-chaîne, puis utilisez la méthode find() pour rechercher cette sous-chaîne dans les deux chaînes de caractères saisies précédemment.
    std::string sous_chaine;
    std::cout << "Entrez une sous-chaîne à rechercher: ";
    std::cin >> sous_chaine;

    // Utilisez la fonction find() pour chercher la sous-chaîne dans les deux chaînes de caractères
    size_t trouve1 = chaine1.find(sous_chaine);
    size_t trouve2 = chaine2.find(sous_chaine);

    // Vérifiez si la sous-chaîne est trouvée dans l'une des chaînes et affichez un message approprié
    if (trouve1 != std::string::npos) {
        std::cout << "La sous-chaîne a été trouvée dans la première chaîne à la position " << trouve1 << std::endl;
    }
    if (trouve2 != std::string::npos) {
        std::cout << "La sous-chaîne a été trouvée dans la deuxième chaîne à la position " << trouve2 << std::endl;
    }
    if (trouve1 == std::string::npos && trouve2 == std::string::npos) {
        std::cout << "Aucune correspondance n'a été trouvée." << std::endl;
    }

    return 0;
}

```

Dans ce morceau de code, chaque étape a été réalisée en utilisant des fonctions pertinentes disponibles avec le type `std::string` en C++. Les commentaires ajoutés dans le code expliquent chaque étape du programme pour faciliter la compréhension.