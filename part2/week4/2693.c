#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[75];
    char regiao;
    int custo;

} Aluno;

int compare(Aluno aluno1, Aluno aluno2) { //retorna 0 ou 1 dizendo se o primeiro tem maior prioridade ou nao na hora de ordenar
    if(aluno1.custo < aluno2.custo)
        return 1;
    else if(aluno1.custo > aluno2.custo)
        return 0;

    //caso das distancias serem iguais
    if(aluno1.regiao < aluno2.regiao)
        return 1;
    else if(aluno1.regiao > aluno2.regiao)
        return 0;

    //caso das distancias serem iguais e das regioes tambem
    if(strcmp(aluno1.nome, aluno2.nome) < 0)
        return 1;
    else
        return 0;
}

void merge(Aluno *v, int l, int m, int r){
    int size_l = (m - l + 1);
    int size_r = (r - m);

    Aluno *vet_l, *vet_r;
    vet_l = (Aluno *) malloc(sizeof(Aluno) * size_l);
    vet_r = (Aluno *) malloc(sizeof(Aluno) * size_r);

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

        else if (compare(vet_l[i], vet_r[j])) //ex: vet_l[i].altura <= vet_r[j].altura
            v[k] = vet_l[i++];
        
        else
            v[k] = vet_r[j++];
    }
    
    free(vet_l);
    free(vet_r);
}

void mergeSort(Aluno *v, int l, int r){
    int m;
    if(l < r){
        m = (l + r)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main() {
    int qtd;
    
    while (scanf("%d", &qtd) != EOF) {
        Aluno *alunos = (Aluno *) malloc(qtd * sizeof(Aluno));

        for (int i = 0; i < qtd; i++){
            getchar();
            scanf("%s", alunos[i].nome);
            getchar();
            scanf("%c", &alunos[i].regiao);
            scanf("%d", &alunos[i].custo);
        }

        mergeSort(alunos, 0, qtd-1);

        for (int i = 0; i < qtd; i++)
            printf("%s\n", alunos[i].nome);

        
        free(alunos);
    }
    
    return 0;
}