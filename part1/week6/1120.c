#include <stdio.h>
#include <string.h>
 
int main() {
    char d, n[101], v[101];
    
    scanf("%c %s", &d, n);
    getchar();
    
    int tam, contador;
    
    while(d != '0' || strcmp(n, "0")){
        tam = strlen(n);
        contador = 0;

        for (int i = 0; i < tam; i++)
        {
            if(n[i] != d){
                v[contador] = n[i];
                contador++;
            }
        }
        v[contador] = '\0';

        while (v[0] == '0' && v[1] != '\0'){
            for (int i = 0; i < contador; i++)
            {
                v[i] = v[i+1];
            }    
        }
        
        if(v[0] == '\0'){
            v[0] = '0';
            v[1] = '\0';
        }

        printf("%s\n", v);
        
        scanf("%c %s", &d, n);
        getchar();
    }
 
    return 0;
}