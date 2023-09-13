#include <stdio.h>

int addition (int a, int b) {

    return a + b;
}

int main () {
    int a;
    int b;
    printf("Entrez un nombre : ");
    scanf("%d",&a);
    printf("Entrez un autre nombre : ");
    scanf("%d",&b);
    int resultat = addition (a, b);
    printf("Le résultat de l'addition de %d et %d vaut : %d\n", a, b, resultat);
    return 0;
}