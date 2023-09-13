#include <stdio.h>

 int main () {
    int nb1;
    int nb2;
    int nb3;
    int nb4;
    int nb5;
    int lg = 0;
    int tableau[5] = {nb1, nb2, nb3, nb4, nb5};
    int somme;

    printf("Entrez 5 valeurs \n");
    scanf("%d %d %d %d %d", &tableau[0], &tableau[1], &tableau[2], &tableau[3], &tableau[4]);
      while (lg < 5) {
        printf("%d \n", tableau[lg]);
        lg = lg + 1;
    }
    
    somme = tableau[0] + tableau[1] + tableau[2] + tableau[3] + tableau[4];
    printf("La somme des valeurs du tableau vaut %d \n", somme);

    while 

    return 0;
}