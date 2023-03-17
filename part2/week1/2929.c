#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cel {
    struct cel *prox;
    int n;
}Celula;

typedef struct {
    Celula *cabeca;
} Pilha;

void pilhaInicia(Pilha *pPilha){
    pPilha->cabeca = (Celula *) malloc(sizeof(Celula));
    pPilha->cabeca->prox = NULL;
}

int pilhaEhVazia(Pilha * pPilha){
    return (pPilha->cabeca->prox == NULL);
}

int pop(Pilha *pPilha){
    if(pilhaEhVazia(pPilha))
        return 0;

    Celula *aux;
    aux = pPilha->cabeca->prox;

    pPilha->cabeca->prox = aux->prox;
    free(aux);
    return 1;
}

void push(Pilha *pPilha, int n){
    Celula *aux = (Celula *) malloc(sizeof(Celula));

    aux->n = n;
    aux->prox = pPilha->cabeca->prox;
    pPilha->cabeca->prox = aux;
}

void liberaPilha(Pilha *pPilha){
    Celula * atual = pPilha -> cabeca;
    Celula * proximo = atual->prox;
    
    while (proximo != NULL){
        free(atual);
        atual = proximo;
        proximo = proximo -> prox;
    }
    free(atual);
}

int min(Pilha *pPilha){
    if(pilhaEhVazia(pPilha))
        return -100;
    int minimo;
    Celula *aux = pPilha->cabeca->prox;
    minimo = 1000000000;

    while (aux!=NULL)
    {
        if(aux->n < minimo)
            minimo = aux->n;

        aux = aux->prox;
    }
    
    return minimo;
}

int main(){
    Pilha pilha;
    pilhaInicia(&pilha);

    int n, aux;
    scanf("%d", &n);
    getchar();

    char str[10];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);

        if(!strcmp("PUSH", str)){
            scanf("%d", &aux);
            getchar();
            push(&pilha, aux);
        }
        else if(!strcmp("POP", str)){
            if(!pop(&pilha))
                printf("EMPTY\n");
        }
        else if(!strcmp("MIN", str)){
            int minimo = min(&pilha);
            if(minimo == -100)
                printf("EMPTY\n");
            else
                printf("%d\n", minimo);
        }
    }
    
    liberaPilha(&pilha);

    return 0;
}