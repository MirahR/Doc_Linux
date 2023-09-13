#include <stdio.h>
#include <string.h>

int MAJ( char chaine[]){
    int nbmaj = 0;
    for (int i; i < strlen(chaine); i++){
        if (chaine[i] >= 65 && chaine[i] <= 90) {
        // ou mettre la condition : if (chaine[i] >= 'A' && chaine[i] <= 'Z')
            nbmaj++;
        }
    }
    return nbmaj;
}

int main() {
    char chaine [] = "BonjOuR";
    printf ("%d\n", MAJ (chaine));


}
