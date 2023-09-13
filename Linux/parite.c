#include <stdio.h> 

int parite ( int a ) {
    printf ("Entrez un nombre : ");
        scanf("%d", &a);
        if (a % 2 == 0) {
            printf ("%d est pair\n", a);
            return 0;
        }
            else {
                printf ("%d est impair\n", a);
                return 1;
            }
}

    int main () {
        int a; 
        parite (a);  
    return 0;
    }