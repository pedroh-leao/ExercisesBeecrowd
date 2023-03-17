#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char opcao[5];
    char nome[100];
} Participante;

void merge(Participante *v, int l, int m, int r){
    int size_l = (m - l + 1);
    int size_r = (r - m);

    Participante *vet_l, *vet_r;
    vet_l = (Participante *) malloc(sizeof(Participante) * size_l);
    vet_r = (Participante *) malloc(sizeof(Participante) * size_r);

    int i, j;
    for (i = 0; i < size_l; i++)
        vet_l[i] = v[i + l];
    
    for (j = 0; j < size_r; j++)
        vet_r[j] = v[m + j + 1];

    i = 0;
    j = 0;
    
    for (int k = l; k <= r; k++){
        if (i == size_l)
            v[k] = vet_r[j++]; 
        
        else if (j == size_r)
            v[k] = vet_l[i++];

        else if (strcmp(vet_l[i].nome, vet_r[j].nome) <= 0) //ex: vet_l[i].altura <= vet_r[j].altura
            v[k] = vet_l[i++];
        
        else
            v[k] = vet_r[j++];
    }
    
    free(vet_l);
    free(vet_r);
}

void mergeSort(Participante *v, int l, int r){
    int m;
    if(l < r){
        m = (l + r)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

void definindoOEscolhido(Participante *v, int n, char *nome){
    int caracteresDoEscolhido = 0;

    for (int i = 0; i <= n; i++){
        if(!strcmp(v[i].opcao, "YES") && strlen(v[i].nome) > caracteresDoEscolhido){
           strcpy(nome, v[i].nome);
           caracteresDoEscolhido = strlen(v[i].nome);
        }
    }
}

int main() {
    Participante participantes[9999];
    int qtdParticipante = -1;
    char nome[100];

    scanf("%s", nome);

    while (strcmp(nome, "FIM")){
        qtdParticipante++;
        strcpy(participantes[qtdParticipante].nome, nome);
        scanf("%s", participantes[qtdParticipante].opcao);

        scanf("%s", nome);
    }

    definindoOEscolhido(participantes, qtdParticipante, nome);

    mergeSort(participantes, 0, qtdParticipante);

    //imprimindo os participantes que digitaram "YES"
    for (int i = 0; i <= qtdParticipante; i++){
        while(!strcmp(participantes[i].nome, participantes[i+1].nome)){
            i++;
            if(i == qtdParticipante)
                break;
        }
        if (!strcmp(participantes[i].opcao, "YES"))
            printf("%s\n", participantes[i].nome);
    }
    
    //imprimindo os participantes que digitaram "NO"
    for (int i = 0; i <= qtdParticipante; i++){
        if (!strcmp(participantes[i].opcao, "NO"))
            printf("%s\n", participantes[i].nome);
    }

    printf("\nAmigo do Habay:\n");
    printf("%s\n", nome);

    return 0;
}