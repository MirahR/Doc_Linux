#include <stdio.h> 
#include <stdbool.h>

bool IsEven( int a ) {
    return (a % 2);
}


int main () {
    int a; 
    printf("Entrer un nombre à tester :\n");;
    scanf("%d", &a);
    if(IsEven(a))
        printf("%d est impair \n", a);
    else
        printf("%d est pair \n", a);
return 0;
}