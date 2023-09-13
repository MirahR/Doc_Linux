#include <stdio.h>

void ft_combinaison(void){;
    for (int i = 0; i <= 7; i++){
        for (int j = i+1; j <= 8; j++){
            for (int k = j+1; k <= 9; k++){
                if (i == 7 && j == 8 && k == 9){
                    printf( "%d%d%d\n", i, j, k);
                } else {
                    printf( "%d%d%d, ", i, j, k); 
                }
            }
        }
    }
}


int main (){
    ft_combinaison();
return 0;    
}

