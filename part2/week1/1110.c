#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    struct cel *pProx;
    int carta;
} Celula;

typedef struct{
    Celula *cabeca;
    Celula *ultimo;
} Lista;

int listaInicia(Lista *pLista){
    pLista->cabeca = (Celula *) malloc(sizeof(Celula));
    if(pLista->cabeca == NULL)
        return 0;

    pLista->cabeca->pProx = NULL; 
    pLista->ultimo = pLista->cabeca;

    return 1;
}

int listaEhVazia(Lista *pLista){
    return pLista->cabeca->pProx == NULL;
}

int listaRetiraPrimeiro(Lista *pLista, int *carta){
    if(listaEhVazia(pLista))
        return 0;

    Celula *aux = pLista->cabeca->pProx;
    
    *carta = aux->carta;
    pLista->cabeca->pProx = aux->pProx;

    free(aux);
    return 1;
}

int listaInsereInicio(Lista *pLista, int carta){
    Celula *aux = (Celula *) malloc(sizeof(Celula));
    if(aux == NULL)
        return 0;

    aux->carta = carta;
    aux->pProx = pLista->cabeca->pProx;

    pLista->cabeca->pProx = aux;

    return 1;
}

int listaInsereFinal(Lista *pLista, int carta){
    Celula *aux = (Celula *) malloc(sizeof(Celula));
    if(aux == NULL)
        return 0;

    aux->carta = carta;
    aux->pProx = NULL;
    pLista->ultimo->pProx = aux;
    pLista->ultimo = aux;

    return 1;
}

void listaImprime(Lista *pLista){
    Celula *aux = pLista->cabeca->pProx;

    if(aux!=NULL){ //if criado apenas por causa da formatação do exercício
        printf(" %d", aux->carta);
        aux = aux->pProx;

        while (aux != NULL)
        {
            printf(", %d", aux->carta);
            aux = aux->pProx;
        }
    }

    printf("\n");
}

void listaEsvazia(Lista *pLista){
    if(!listaEhVazia(pLista)){
        int carta;
        while(listaRetiraPrimeiro(pLista, &carta));
    }

    free(pLista->cabeca);
}

int listaMoveTopoBase(Lista *pLista){
    if(listaEhVazia(pLista))
        return 0;

    int cartaAux;
    listaRetiraPrimeiro(pLista, &cartaAux);
    listaInsereFinal(pLista, cartaAux);
    return 1;
}

int main(){
    int nCartas;
    scanf("%d", &nCartas);

    Lista descartadas, cartasOriginais;
    
    int i, cartaAuxiliar;
    while (nCartas != 0){
        listaInicia(&cartasOriginais);
        listaInicia(&descartadas);  
        for (i = 1; i <= nCartas; i++){
            listaInsereFinal(&cartasOriginais, i);
        }

        listaRetiraPrimeiro(&cartasOriginais, &cartaAuxiliar);
        listaInsereFinal(&descartadas, cartaAuxiliar);

        for(i = 0; i < nCartas-2; i++){
            listaMoveTopoBase(&cartasOriginais);
            
            listaRetiraPrimeiro(&cartasOriginais, &cartaAuxiliar);
            listaInsereFinal(&descartadas, cartaAuxiliar);
        }
        
        printf("Discarded cards:");
        listaImprime(&descartadas);

        printf("Remaining card:");
        listaImprime(&cartasOriginais);

        scanf("%d", &nCartas);

        listaEsvazia(&cartasOriginais);
        listaEsvazia(&descartadas);
    }

    return 0;
}