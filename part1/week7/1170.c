#include <stdio.h>

int main(){
    int n, cont;
    float comida;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%f", &comida);

        cont = 0;

        while (comida > 1)
        {
            comida /= 2;
            cont++;
        }

        printf("%d dias\n", cont);
    }
    

    return 0;
}