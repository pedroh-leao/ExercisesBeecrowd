#include <stdio.h>
#include <stdlib.h>

int* alocaVetor(int n){
    return (int *) malloc(n * sizeof(int));
}

void desalocaVetor(int *vetor){
    free(vetor);
}

void merge(int *v, int l, int m, int r){
    int size_l = m - l + 1;
    int size_r = r - m;

    int *vet_l, *vet_r;
    vet_l = alocaVetor(size_l);
    vet_r = alocaVetor(size_r);

    int i, j;

    for (i = 0; i < size_l; i++)
        vet_l[i] = v[i + l];

    for(j = 0; j < size_r; j++)
        vet_r[j] = v[m + j + 1];

    //marcadores de posição
    i=0;
    j=0;

    for (int k = l; k <= r; k++){
        if(i == size_l)
            v[k] = vet_r[j++];

        else if(j == size_r)
            v[k] = vet_l[i++];
        
        else if(vet_l[i] <= vet_r[j])
            v[k] = vet_l[i++];

        else
            v[k] = vet_r[j++];
    }

    desalocaVetor(vet_l);
    desalocaVetor(vet_r);    
}

void mergeSort(int *v, int l, int r){
    int m;
    
    if(l<r){
        m = (l+r)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main(){
    int n, aux;
    scanf("%d", &n);

    int *vPares, *vImpares;
    
    vPares = alocaVetor(n);
    vImpares = alocaVetor(n);

    int contPar = 0, contImpar = 0, i;

    for (i = 0; i < n; i++){
        scanf("%d", &aux);

        if(aux % 2 == 0)
            vPares[contPar++] = aux;
        else
            vImpares[contImpar++] = aux;
    }
    
    mergeSort(vPares, 0, contPar-1);
    mergeSort(vImpares, 0, contImpar-1);

    for (i = 0; i < contPar; i++)
        printf("%d\n", vPares[i]);
    
    for (i = contImpar-1; i >= 0; i--)
        printf("%d\n", vImpares[i]);
    

    desalocaVetor(vPares);
    desalocaVetor(vImpares);

    return 0;
}