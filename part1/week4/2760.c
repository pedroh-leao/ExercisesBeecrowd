#include <stdio.h>
#include <string.h>
#define TAM_MAX 100

int main(){

    char frase1[TAM_MAX+2];
    char frase2[TAM_MAX+2];
    char frase3[TAM_MAX+2];

    fgets(frase1, TAM_MAX, stdin);
    fgets(frase2, TAM_MAX, stdin);
    fgets(frase3, TAM_MAX, stdin);

    frase1[strlen(frase1)-1]='\0';
    frase2[strlen(frase2)-1]='\0';
    frase3[strlen(frase3)-1]='\0';


    int n1 = strlen(frase1), n2 = strlen(frase2), n3 = strlen(frase3);
    
    printf("%s%s%s\n", frase1, frase2, frase3);
    printf("%s%s%s\n", frase2, frase3, frase1);
    printf("%s%s%s\n", frase3, frase1, frase2);

    for(int i=0; i < (n1>10?10:n1); i++){
        printf("%c",frase1[i]);
    }
    for(int i=0; i < (n2>10?10:n2); i++){
        printf("%c",frase2[i]);
    }
    for(int i=0; i < (n3>10?10:n3); i++){
        printf("%c",frase3[i]);
    }
    printf("\n");
    return 0;
}