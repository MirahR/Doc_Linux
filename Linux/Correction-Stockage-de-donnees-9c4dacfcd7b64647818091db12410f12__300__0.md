# Correction - Stockage de données

Voici la solution de l'exercice :

```cpp

#include <iostream>
#include <vector>
#include <string>

template <typename T>
class StockageDonnees {
private:
    std::vector<T> donnees;

public:
    void ajouterDonnee(const T& donnee) {
        donnees.push_back(donnee);
    }

    T obtenirDonnee(int indice) const {
        if (indice >= 0 && indice < donnees.size()) {
            return donnees[indice];
        } else {
            throw std::out_of_range("Indice hors limites.");
        }
    }

    int taille() const {
        return donnees.size();
    }
};

int main() {
    // Création d'un objet StockageDonnees générique
    StockageDonnees<int> stockageInt;
    stockageInt.ajouterDonnee(42);
    stockageInt.ajouterDonnee(10);

    StockageDonnees<std::string> stockageString;
    stockageString.ajouterDonnee("Bonjour");
    stockageString.ajouterDonnee("C++");

    StockageDonnees<double> stockageDouble;
    stockageDouble.ajouterDonnee(3.14);
    stockageDouble.ajouterDonnee(2.718);

    // Affichage des données stockées
    std::cout << "Données stockées dans stockageInt : " << std::endl;
    for (int i = 0; i < stockageInt.taille(); i++) {
        std::cout << stockageInt.obtenirDonnee(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Données stockées dans stockageString : " << std::endl;
    for (int i = 0; i < stockageString.taille(); i++) {
        std::cout << stockageString.obtenirDonnee(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Données stockées dans stockageDouble : " << std::endl;
    for (int i = 0; i < stockageDouble.taille(); i++) {
        std::cout << stockageDouble.obtenirDonnee(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}

```