#include <stdio.h>

void swap(char *v, int pos1, int pos2){
    char temp = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp;
}

int selectionSort(char *v, int n) {
    int min, swaps = 0;

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
            
            if(swaps > 1)
                return 0;
        }
    }

    return 1;
}

int main() {
    int testeCases;
    scanf("%d", &testeCases);

    int strlen;
    char str[26];

    for (int i = 0; i < testeCases; i++){
        scanf("%d", &strlen);
        getchar();
        scanf("%s", str);
        
        if(selectionSort(str, strlen) == 1){
            printf("There are the chance.\n");
        }
        else{
            printf("There aren't the chance.\n");
        }
    }
    

    return 0;
}