#include <stdio.h>
#include <stdlib.h>

void permutate(int* niSoldiers, int start, int end, int *qiSoldiers, int *nongloniaWins) {
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
}

int main(){
    int numSoldiers;
    scanf("%d", &numSoldiers);

    int *qiSoldiers = (int *) malloc(numSoldiers * sizeof(int));
    for(int i = 0; i < numSoldiers; i++)
        scanf("%d", &qiSoldiers[i]);

    int *niSoldiers = (int *) malloc(numSoldiers * sizeof(int));
    for(int i = 0; i < numSoldiers; i++)
        scanf("%d", &niSoldiers[i]);


    int nongloniaWins = 0;

    permutate(niSoldiers, 0, numSoldiers-1, qiSoldiers, &nongloniaWins);

    free(qiSoldiers);
    free(niSoldiers);

    printf("%d\n", nongloniaWins);

    return 0;
}