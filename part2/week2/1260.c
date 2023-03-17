#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[32];
    int qtd;
}Arvore;


void trocaPosicao(Arvore* arvores, int * i, int * j){
    Arvore auxiliar;

    auxiliar = arvores[*i];
    arvores[*i] = arvores[*j];
    arvores[*j] = auxiliar;
    *i += 1;
    *j -= 1;
}


void quicksort(Arvore * arvores, int inicio, int fim){
    int i, j;
    Arvore pivo; 

    i = inicio;
    j = fim;
    pivo = arvores[(inicio + fim) / 2];

    while (i <= j){
        while (strcmp(arvores[i].nome, pivo.nome) < 0 && i < fim)
            i++;
        
        while (strcmp(arvores[j].nome, pivo.nome) > 0 && j > inicio)
            j--;

        if (i <= j)
            trocaPosicao(arvores, &i, &j);
    }

    if (j > inicio)
        quicksort(arvores, inicio, j);

    if (i < fim)
        quicksort(arvores, i, fim);
}

int main(){
    int n;
    scanf("%d", &n);

    int qtdArvores;
    Arvore *arvores;

    getchar();
    getchar();
    int cont;

    for (int i = 0; i < n; i++){
        arvores = (Arvore *) malloc(1000000 * sizeof(Arvore));
        qtdArvores = 0;
        cont = 0;
        do
        {
            arvores[qtdArvores].nome[0]='\0';
            fgets(arvores[qtdArvores].nome, 32, stdin);

            if(arvores[qtdArvores].nome[strlen(arvores[qtdArvores].nome) - 1] == '\n')
                arvores[qtdArvores].nome[strlen(arvores[qtdArvores].nome) - 1] = '\0'; //retirando o \n
            
            qtdArvores++;

        } while (arvores[qtdArvores-1].nome[0] != '\0');
        qtdArvores--;

        quicksort(arvores, 0, qtdArvores-1);

        for (int j = 0; j < qtdArvores; j++){
            arvores[j].qtd = 1;
            
            cont = j + 1;
            while (cont < qtdArvores && !strcmp(arvores[j].nome, arvores[cont].nome)){
                arvores[j].qtd++;
                cont ++;
            }

            printf("%s %.4lf\n", arvores[j].nome, ((double)arvores[j].qtd/qtdArvores)*100);

            j = cont - 1;
        }            
        
        if(i != n-1)
            printf("\n");

        free(arvores);
    }

    return 0;
}