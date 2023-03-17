#include <stdio.h>
#include <string.h>

int encaixa(char *n1, char *n2){
	int contadorN1, tamN2;
    contadorN1 = strlen(n1) - 1;
    tamN2 = strlen(n2);

    for(int i = tamN2 - 1; i>=0; i--){
        if(n1[contadorN1] != n2[i])
            return 0;
        contadorN1--;
    }
    return 1;
}
 
int main() {
    int n;
    char n1[1000], n2[1000];
    scanf("%d", &n);    
    getchar();
     for(int i=0; i<n; i++){
         scanf("%s %s", n1, n2);

         if(encaixa(n1, n2))
            printf("encaixa\n");
        else
            printf("nao encaixa\n");
     }
 
    return 0;
}