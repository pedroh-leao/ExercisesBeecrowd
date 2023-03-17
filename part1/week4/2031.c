#include <stdio.h>
#include <string.h>

int transformador(char str[10]){
    
    if(strcmp(str, "ataque\n")==0){
        return 1;
    }
    else if(strcmp(str, "pedra\n")==0){
        return 2;
    }
    else{
        return 3;
    }
}

int main(){

    int casos_de_teste;
    char str1[10], str2[10];
    int j1, j2;
    scanf("%d", &casos_de_teste);
    getchar();

    for(int i=0; i<casos_de_teste; i++){
        fgets(str1, 10, stdin);
        fgets(str2, 10, stdin);

        j1 = transformador(str1);
        j2 = transformador(str2);

        /*
            Ataque 1
            Pedra 2
            Papel 3
        */
        if(j1 == 1 && j2 == 2){
            printf("Jogador 1 venceu\n");
        }
        else if(j1 == 2 && j2 ==1){
            printf("Jogador 2 venceu\n");
        }

        else if(j1 == 2 && j2 == 3){
            printf("Jogador 1 venceu\n");
        }
        else if(j1 == 3 && j2 ==2){
            printf("Jogador 2 venceu\n");
        }

        else if(j1 == 3 && j2 == 1){
            printf("Jogador 2 venceu\n");
        }
        else if(j1 == 1 && j2 ==3){
            printf("Jogador 1 venceu\n");
        }

        else if(j1 == 3 && j2 == 3){
            printf("Ambos venceram\n");
        }

        else if(j1 == 2 && j2 == 2){
            printf("Sem ganhador\n");
        }

        else{
            printf("Aniquilacao mutua\n");
        }


    }


    return 0;
}