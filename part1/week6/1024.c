#include <stdio.h>
#include <string.h>
 
int main() {
    int n, tam;
    scanf("%d", &n); //casos de teste
    char aux;
    
    char str[1002];
    getchar();
    for(int i=0; i<n; i++){
        fgets(str, 1002, stdin);
        str[strlen(str) - 1] = '\0';
        tam = strlen(str);
        
        for(int j =0; j<tam; j++){
            if((str[j]>=65 && str[j]<=90) || (str[j]>=97 && str[j]<=122))
                str[j] = str[j] + 3;
        }
        
        for(int k =0; k<tam/2; k++){
            aux = str[k];
            str[k] = str[tam-1-k];
            str[tam-1-k] = aux;
        }
        
        if(tam % 2 == 0){
            for(int m = (tam/2); m<tam; m++){
                str[m] = str[m] - 1;
            }
        }
        else{
            for(int n = (tam-1)/2; n<tam; n++){
                str[n] = str[n] - 1;
            }
        }
        
        printf("%s\n", str);
    }
 
    return 0;
}