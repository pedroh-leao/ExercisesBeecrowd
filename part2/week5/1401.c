#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char *v, int l, int m, int r){
    int size_l = (m-l+1);
    int size_r = (r-m);

    char *vet_l = (char *) malloc(size_l * sizeof(char));
    char *vet_r = (char *) malloc(size_r * sizeof(char));
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

        else if(vet_l[i] <= vet_r[j]) 
            v[k] = vet_l[i++];

        else
            v[k] = vet_r[j++];
    }
    
    free(vet_l);
    free(vet_r);
}

void sort(char *v, int l, int r){ //merge Sort
    int m;
    
    if(l<r){
        m = (l+r) / 2;
        sort(v, l, m);
        sort(v, m+1, r);
        merge(v, l, m, r);
    }
}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

int next_permutation(char *s, int n) {
    int i, j;
    for (i = n - 2; i >= 0; i--) {
        if (s[i] < s[i + 1]) {
            break;
        }
    }
    if (i < 0) {
        return 0;
    }
    for (j = n - 1; j > i; j--) {
        if (s[j] > s[i]) {
            break;
        }
    }
    swap(&s[i], &s[j]);
    for (i = i + 1, j = n - 1; i < j; i++, j--) {
        swap(&s[i], &s[j]);
    }
    return 1;
}

void permute(char *s, int n) {
    char prev[n];
    strcpy(prev, s);
    printf("%s\n", prev);
    while (next_permutation(s, n)) {
        if (strcmp(s, prev) != 0) {
            strcpy(prev, s);
            printf("%s\n", prev);
        }
    }
}


int main(){
    int n;
    scanf("%d",&n);
    
    char str[11];

    for (int i = 0; i < n; i++){
        getchar();
        scanf("%s", str);

        sort(str, 0, strlen(str)-1);

        permute(str, strlen(str));
        
        if(i != n-1)
            printf("\n");
    }
    printf("\n");
    return 0;
}