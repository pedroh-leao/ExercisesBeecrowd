#include <stdio.h>
#include <string.h>
 
int main() {
    int n, numCobaias;
    char cobaia;
    int total=0, rato=0, sapo=0, coelho=0;

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++)
    {
        scanf("%d %c", &numCobaias, &cobaia);

        total += numCobaias;
        if(cobaia == 'R')
            rato+= numCobaias;
        else if(cobaia == 'S')
            sapo+= numCobaias;
        else
            coelho+=numCobaias;
    }

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", coelho);
    printf("Total de ratos: %d\n", rato);
    printf("Total de sapos: %d\n", sapo);
    printf("Percentual de coelhos: %.2f %%\n", (float)coelho/total*100);
    printf("Percentual de ratos: %.2f %%\n", (float)rato/total*100);
    printf("Percentual de sapos: %.2f %%\n", (float)sapo/total*100);
 
    return 0;
}