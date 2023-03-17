#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
    return a < b ? a : b;
}

int usedPatch(int punctures, int tireLength, int t1, int t2, int* puncturesDistance, int pos1, int pos2, int *mem_rem) {
    int j, used1, used2;

    if (mem_rem[pos1] > 0) 
        return mem_rem[pos1];

    if (puncturesDistance[pos1] - puncturesDistance [pos2] <= t1) 
        used1 = t1;
    else {
        j = punctures;
        while (j-- > 0)
            if (puncturesDistance[pos1] - puncturesDistance[j] > t1) 
                break;
        used1 = usedPatch(punctures, tireLength, t1, t2, puncturesDistance, j, pos2, mem_rem) + t1;
    }

    if (puncturesDistance[pos1] - puncturesDistance[pos2] <= t2) 
        used2 = t2;
    else {
        j = punctures;

        while (j-- > 0)
            if(puncturesDistance[pos1] - puncturesDistance[j] > t2) 
                break;

        used2 = usedPatch(punctures , tireLength , t1 , t2 , puncturesDistance , j , pos2, mem_rem) + t2;
    }

    mem_rem[pos1] = min(used1 , used2);

    return mem_rem[pos1];
}

int main () {
    int i ,j , punctures , tireLength , t1 , t2 ;
    int mem_rem[1000];

    while (scanf("%d %d %d %d", &punctures, &tireLength, &t1, &t2) != EOF) {
        for (i = 0; i < 1000; i ++)
            mem_rem[i] = 0;

        int* puncturesDistance = (int *) malloc(punctures * sizeof(int)) ;
        for (i = 0; i < punctures; i ++) 
            scanf ("%d", &puncturesDistance[i]) ;

        for (i = 0; i < punctures; i ++)
            for (j = 0; j < punctures; j ++) {
                if(i != j)
                    usedPatch (punctures, tireLength, t1, t2, puncturesDistance, i, j, mem_rem);
            }

        printf("%d\n", mem_rem[punctures - 1]);

        free(puncturesDistance);
    }

    return 0;
}
