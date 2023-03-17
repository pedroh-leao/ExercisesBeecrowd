#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int altura;
} Pessoa;

void merge(Pessoa *v, int l, int m, int r){
    int size_l = (m - l + 1);
    int size_r = (r - m);

    Pessoa *vet_l, *vet_r;
    vet_l = (Pessoa *) malloc(sizeof(Pessoa) * size_l);
    vet_r = (Pessoa *) malloc(sizeof(Pessoa) * size_r);

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

        else if (vet_l[i].altura <= vet_r[j].altura)
            v[k] = vet_l[i++];
        
        else
            v[k] = vet_r[j++];
    }
    
    free(vet_l);
    free(vet_r);
}

void mergeSort(Pessoa *v, int l, int r){
    int m;
    if(l < r){
        m = (l + r)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main(){
    int nc, qtdPessoas;
    Pessoa *pessoas;

    scanf("%d", &nc);

    for(int i = 0; i < nc; i++){
        scanf("%d", &qtdPessoas);

        pessoas = (Pessoa *) malloc(sizeof(Pessoa) * qtdPessoas);
        
        for(int j = 0; j < qtdPessoas; j++)
            scanf("%d", &pessoas[j].altura);

        mergeSort(pessoas, 0, qtdPessoas-1);

        printf("%d", pessoas[0].altura);
        for(int j = 1; j < qtdPessoas; j++)
            printf(" %d", pessoas[j].altura);
        
        printf("\n");
        free(pessoas);
    }

    return 0;
}