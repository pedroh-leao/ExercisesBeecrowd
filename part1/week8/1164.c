#include <stdio.h>

int numPerfeito(int x){
    int soma = 0;
    for (int i = 1; i < x; i++)
    {
        if(x % i == 0)
            soma += i;
    }
    
    if(x == soma)
        return 1;
    else
        return 0;
}

int main(){
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);

        if(numPerfeito(x))
            printf("%d eh perfeito\n", x);
        else
            printf("%d nao eh perfeito\n", x);
    }
    

    return 0;
}