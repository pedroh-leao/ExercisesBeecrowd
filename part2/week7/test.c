#include <stdio.h>
#include <stdlib.h>

//testing to the exercise 2095

/*void permutate(int* niSoldiers, int start, int end, int *qiSoldiers, int *nongloniaWins) {
    if (start == end) { // base case: end of vector
        int niWins = 0;

        for (int i = 0; i <= end; i++) 
            if(niSoldiers[i] > qiSoldiers[i])
                niWins++;

        if(niWins > *nongloniaWins)
            *nongloniaWins = niWins;

    } 
    else {
        for (int i = start; i <= end; i++) {
            // swap the current element with the first one
            int temp = niSoldiers[start];
            niSoldiers[start] = niSoldiers[i];
            niSoldiers[i] = temp;
            
            // call the function recursively for the rest of the vector
            permutate(niSoldiers, start+1, end, qiSoldiers, nongloniaWins);
            
            // undo the swap to avoid influencing the next iterations
            temp = niSoldiers[start];
            niSoldiers[start] = niSoldiers[i];
            niSoldiers[i] = temp;
        }
    }
}*/

/*void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int next_permutation(int *niSoldiers, int n) {
    int i, j;
    for (i = n - 2; i >= 0; i--) {
        if (niSoldiers[i] < niSoldiers[i + 1]) {
            break;
        }
    }
    if (i < 0) {
        return 0;
    }
    for (j = n - 1; j > i; j--) {
        if (niSoldiers[j] > niSoldiers[i]) {
            break;
        }
    }
    swap(&niSoldiers[i], &niSoldiers[j]);
    for (i = i + 1, j = n - 1; i < j; i++, j--) {
        swap(&niSoldiers[i], &niSoldiers[j]);
    }
    return 1;
}

void permute(int *niSoldiers, int n, int *qiSoldiers, int *nongloniaWins) {
    int niWins = 0;

        for (int i = 0; i <= n; i++) 
            if(niSoldiers[i] > qiSoldiers[i])
                niWins++;

        if(niWins > *nongloniaWins)
            *nongloniaWins = niWins;

    while (next_permutation(niSoldiers, n)) {
        niWins = 0;

        for (int i = 0; i <= n; i++) 
            if(niSoldiers[i] > qiSoldiers[i])
                niWins++;

        if(niWins > *nongloniaWins)
            *nongloniaWins = niWins;
    }
}*/

void permutate(int* arr, int start, int end) {
    if (start == end) { // Base case: chegamos ao fim do vetor
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            // Trocamos o elemento atual com o primeiro elemento
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
            
            // Chamamos recursivamente a função para o restante do vetor
            permutate(arr, start+1, end);
            
            // Desfazemos a troca para evitar influenciar as próximas iterações
            temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int arr[] = {2, 7, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    permutate(arr, 0, n-1);
    return 0;
}