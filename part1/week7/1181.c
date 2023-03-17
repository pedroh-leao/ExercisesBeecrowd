#include <stdio.h>

int main(){
    int linha;
    char op;
    float matriz[12][12], soma = 0;

    scanf("%d", &linha);
    getchar();

    scanf("%c", &op);

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            scanf("%f", &matriz[i][j]);
        }
        
    }    

    for (int i = 0; i < 12; i++)
    {
        soma += matriz[linha][i];
    }

    if(op == 'M')
        soma /= 12;

    printf("%.1f\n", soma);    

    return 0;
}