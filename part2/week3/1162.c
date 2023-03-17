#include <stdio.h>
#include <stdlib.h>

void swap(int *v, int pos1, int pos2){
    int aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
}
void ordena(int *v, int n, int *trocas){ //bubbleSort
    int trade = 0;
    for (int i = 0; i < n; i++){
        for (int j = 1; j < n-i; j++){
            if(v[j] < v[j-1]){
                swap(v, j, j-1);
                *trocas += 1;
                trade++;
            }
        }
        if(trade == 0)
            break;
    }
}

int main(){
    int casos, numVagoes, *vagoes, trocas;
    
    scanf("%d", &casos);

    for (int i = 0; i < casos; i++){
        scanf("%d", &numVagoes);
        vagoes = (int *) malloc(numVagoes * sizeof(int));

        for (int i = 0; i < numVagoes; i++){
            scanf("%d", &vagoes[i]);
        }

        trocas = 0;

        ordena(vagoes, numVagoes, &trocas);

        printf("Optimal train swapping takes %d swaps.\n", trocas);
        
        free(vagoes);
    }
    

    return 0;
}