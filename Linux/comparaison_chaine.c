#include <stdio.h>
#include <string.h>

int compar( char chaine1[], char chaine2[]){
    int lens1 = strlen(chaine1);
    int lens2 = strlen(chaine2);
    if (lens1 == lens2){
        for (int i=0; i < lens1; i++){
            if (chaine1[i] != chaine2[i]){
                printf("les chaines de charactères sont différentes\n");
                return 1; 
            }
        }
        printf("les chaines de charactères sont identiques\n");
        return 0;
    } else {
        printf("les chaines de charactères sont différentes\n");
        return 1;  
    }
}

int main() {
	char chaine1[] = "intru";
    char chaine2[] = "intru";


//    printf("la taille de la chaine 1 vaut %d\n", lens1);
//    printf("la taille de la chaine 2 vaut %d\n", lens2);

    compar(chaine1,chaine2);

}



