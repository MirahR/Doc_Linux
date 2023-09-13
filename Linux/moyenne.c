#include <stdio.h> 

float moyenne (float a, float b, float c) {
    return ( (a + b + c) / 3 );
}

float main () {
    float a;
    float b;
    float c;
    printf ("Entrez un nombre : ");
    scanf ("%f", &a);
    printf ("Entrez un deuxième nombre : ");
    scanf ("%f", &b);
    printf ("Entrez un troisième nombre : ");
    scanf ("%f", &c);
    float resultat = moyenne (a, b, c);
    printf ("La moyenne de %f, %f et %f vaut : %f\n", a, b, c, resultat);
    return 0;
}