# Correction - Operations sur chaînes

```cpp
#include <iostream>
#include <string> // Utiliser ce header pour la classe std::string
#include <array> // Inclure ce header pour la classe std::array
#include <vector> // Inclure ce header pour la classe std::vector

int main() {
  // Etape 1
  std::string film1 = "Bienvenue à Zombieland";

  // Etape 2
  // Ici on utilise std::array avec la taille 19, étant donné le nombre de caractères dans "Pirate des Caraibes"
  std::array<char, 19> film2 = {'P', 'i', 'r', 'a', 't', 'e', ' ', 'd', 'e', 's', ' ', 'C', 'a', 'r', 'a', 'i', 'b', 'e', 's'};
  // Vous pouvez également utiliser std::vector comme cela :
  // std::vector<char> film2 = {'P', 'i', 'r', 'a', 't', 'e', ' ', 'd', 'e', 's', ' ', 'C', 'a', 'r', 'a', 'i', 'b', 'e', 's'};

  // Etape 3
  std::string film_concate_1 = film1 + "\\n" + std::string(film2.begin(), film2.end());
  std::string film_concate_2 = film1;
  film_concate_2.append("\\n").append(film2.begin(), film2.end());

  // Etape 4
  std::cout << "Longueur de film_concate_1: " << film_concate_1.length() << std::endl;
  std::cout << "Longueur de film_concate_2: " << film_concate_2.length() << std::endl;

  // Etape 5
  bool comparaison_operateur = (film_concate_1 == film_concate_2);
  int comparaison_methode = film_concate_1.compare(film_concate_2);

  std::cout << "Résultats de comparaison : " << std::endl;
  std::cout << "Opérateur == : " << comparaison_operateur << std::endl;
  std::cout << "Méthode compare() : " << (comparaison_methode == 0) << std::endl;

  // Etape 6
  bool films_diff = (film1 != std::string(film2.begin(), film2.end()));
  std::cout << "Film1 et Film2 sont différents : " << films_diff << std::endl;

  return 0;
}

```

Dans cette correction, chaque étape est implémentée en suivant l'énoncé du TP. Les commentaires au-dessus de chaque étape expliquent brièvement ce qui a été fait. Le code effectue toutes les opérations mentionnées dans l'énoncé et doit générer les résultats attendus.