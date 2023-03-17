#include <stdio.h>
#include <stdlib.h>

void swap(int *v, int pos1, int pos2){
    int aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
}

/*int selectionSort(int *v, int n) {
    int min;
    int swaps = 0;

    for (int i = 0; i < n; i++){
        min = i;

        for(int j = i + 1; j < n; j++){
            if(v[j] < v[min]){
                min = j;
            }
        }

        if(min != i){
            swap(v, min, i);
            swaps++;
        }
    }

    return swaps;
}*/

int sort(int *v, int n){ //works only when the array is an integer array like (1 ... N)
    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i] != i+1){
            for(int j = i; j < n; j++){
                if(v[j] == i+1){
                    swap(v, i, j);
                    swaps++;
                }
            }
        }
    }

    return swaps;
}

int main(){
    int instances; // number of instances
    int n; // number of int
    int *v;
    scanf("%d", &instances);

    int i, j, swaps;
    for (i = 0; i < instances; i++){
        scanf("%d", &n);
        v = (int*) malloc(n * sizeof(int));

        for (j = 0; j < n; j++)
            scanf("%d", &v[j]);

        
        swaps = sort(v, n);

        printf("%d\n", swaps);

        free(v);
    }

    return 0;
}