#include <stdio.h>

int main() {
	char chaine[12] = "jeazoajfaoea";
    int voyelle = 0;

    for (int i = 0; i < 12; i++){
        if (chaine[i] == 'a' || chaine[i] == 'e' || chaine[i] == 'i' || chaine[i] == 'o' || chaine[i] == 'u' || chaine[i] == 'y'){
            voyelle = voyelle + 1;
            }
    }
    printf("Il y a %d voyelles dans la chaine\n", voyelle);
    return 0;
return 0;
}