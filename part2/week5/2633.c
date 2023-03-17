#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[21];
    int expirationDate;
} Meat;

void printMeats(Meat *meats, int n){
    printf("%s", meats[0].name);
    for (int i = 1; i < n; i++)
        printf(" %s", meats[i].name);
    
    printf("\n");
}

void merge(Meat *v, int l, int m, int r){
    int size_l = (m-l+1);
    int size_r = (r-m);

    Meat *vet_l = (Meat *) malloc(size_l * sizeof(Meat));
    Meat *vet_r = (Meat *) malloc(size_r * sizeof(Meat));
    int i, j;

    for (i = 0; i < size_l; i++)
        vet_l[i] = v[i + l];

    for(j = 0; j < size_r; j++)
        vet_r[j] = v[m + j + 1];
    
    i = 0;
    j = 0;

    for (int k = l; k <= r; k++){
        if(i == size_l)
            v[k] = vet_r[j++];

        else if(j == size_r)
            v[k] = vet_l[i++];

        else if(vet_l[i].expirationDate <= vet_r[j].expirationDate)
            v[k] = vet_l[i++];

        else
            v[k] = vet_r[j++];
    }
    
    free(vet_l);
    free(vet_r);
}

void sort(Meat *v, int l, int r){ //merge Sort
    int m;
    
    if(l<r){
        m = (l+r) / 2;
        sort(v, l, m);
        sort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main() {
    int n; // number of meats
    Meat *meats;

    int i;

    while (scanf("%d", &n) != EOF) {
        meats = (Meat *) malloc(n * sizeof(Meat));
        
        for (i = 0; i < n; i++){
            scanf("%s", meats[i].name);
            scanf("%d", &meats[i].expirationDate);
        }

        sort(meats, 0, n-1);
        
        printMeats(meats, n);
        
        free(meats);
    }

    return 0;
}