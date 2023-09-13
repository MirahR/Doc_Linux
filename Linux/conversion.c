#include <stdio.h> 

float conversion (float a) {
    return ( a * 9 / 5 + 32 );
}

float main () {
    float a;
    printf ("Entrez la température en degré Celsius : \n");
    scanf ("%f", &a);
    float resultat = conversion ( a );
    printf ("La température %.2f°C vaut %.2f°F\n", a, resultat);
    return 0;
}