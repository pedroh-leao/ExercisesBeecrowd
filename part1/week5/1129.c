#include <stdio.h>
 
int main() {
    int n, test[5], alternativasSelecionadas, alternativa;
    
    scanf("%d", &n);
    while(n != 0){
        for(int i=0; i<n; i++){
            alternativasSelecionadas = 0;
            for(int j=0; j<5; j++){
                scanf("%d", &test[j]);
                if(test[j] <= 127){
                    alternativasSelecionadas++;
                    alternativa = j+1;
                }
            }
            
            if(alternativasSelecionadas == 1){
                switch (alternativa){
                    case 1:
                        printf("A\n");
                        break;
                    
                    case 2:
                        printf("B\n");
                        break;

                    case 3:
                        printf("C\n");
                        break;

                    case 4:
                        printf("D\n");
                        break;

                    default:
                        printf("E\n");
                        break;
                }
            }
            else
                printf("*\n");
        }
        
        scanf("%d", &n);
    }
 
    return 0;
}