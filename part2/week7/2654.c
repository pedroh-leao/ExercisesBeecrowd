#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int power;
    int kills;
    int deaths;
    char name[102];
}God;

int compare(God god1, God god2){
    if (god1.power > god2.power)
        return 1;

    else if(god1.power == god2.power && god1.kills > god2.kills)
        return 1;
    
    else if(god1.power == god2.power && god1.kills == god2.kills && god1.deaths < god2.deaths)
        return 1;

    else if(god1.power == god2.power && god1.kills == god2.kills && god1.deaths == god2.deaths && strcmp(god1.name, god2.name) < 0)
        return 1;

    return 0;
}

void merge(God *v, int l, int m, int r){
    int size_l = (m-l+1);
    int size_r = (r-m);

    God *vet_l = malloc(size_l * sizeof(God));
    God *vet_r = malloc(size_r * sizeof(God));
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

        else if(compare(vet_l[i], vet_r[j]))
            v[k] = vet_l[i++];

        else
            v[k] = vet_r[j++];
    }
    
    free(vet_l);
    free(vet_r);
}

void sortGods(God *v, int l, int r){
    int m;
    
    if(l<r){
        m = (l+r) / 2;
        sortGods(v, l, m);
        sortGods(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    God *gods = (God*) malloc(n * sizeof(God));

    for (int i = 0; i < n; i++){
        scanf("%s %d %d %d", gods[i].name, &gods[i].power, &gods[i].kills, &gods[i].deaths);
    }
    
    sortGods(gods, 0, n-1);
    printf("%s\n", gods[0].name);

    free(gods);

    return 0;
}