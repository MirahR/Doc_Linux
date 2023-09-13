#include <stdio.h>

// Déclaration de la fonction
// type de return de la fonction : void (la fonction ne renvoie rien)
void nomdelafonction() // Nombre et le type d'argument (type nomargument)
{
    // instructions
    // void peut être utilisé pour afficher un truc à l'utilisateur
    //int a = 0;
    //int min = -2147483648;
    //int max = 2147483647;

    //float b = 0.0;
    //float min = -3.4E38;
    //float max = 3.4E38;



    printf("Hello World !\n");
}

int carre(int x)
{
    return x*x;
}


int main()
{
    printf("%d\n", carre(2));
    return 0;
}