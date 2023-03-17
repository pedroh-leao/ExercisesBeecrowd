#include <stdio.h>
 
int main() {
 
    int positivos = 0;
    float n, soma = 0;
    
    for(int i = 1; i<=6; i++){
        scanf("%f", &n);
        if(n>0){
            positivos++;
            soma += n;
        }
    }
    
    printf("%d valores positivos\n", positivos);
    printf("%.1f\n", soma/positivos);
 
    return 0;
}