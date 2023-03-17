#include <stdio.h>

int main(){
    int x, z;

    scanf("%d", &x);

    do
    {
        scanf("%d", &z);
    } while (z<=x);

    int cont = 0, soma = 0;
    while (soma <= z)
    {
        soma += x;
        x++;
        cont++;
    }

    printf("%d\n", cont);    

    return 0;
}