#include <stdio.h>

void leDados(int *n1, int *n2, int *d1, int *d2, char *op){
    scanf("%d", n1);
    getchar();
    getchar();
    scanf("%d", d1);
    getchar();
    scanf("%c", op);
    scanf("%d", n2);
    getchar();
    getchar();
    scanf("%d", d2);
}

void soma(int n1, int d1, int n2, int d2, int *numerador, int *denominador){
    *numerador = n1*d2 + n2*d1;
    *denominador = d1*d2;
}

void subtracao(int n1, int d1, int n2, int d2, int *numerador, int *denominador){
    *numerador = n1*d2 - n2*d1;
    *denominador = d1*d2;
}

void multiplicacao(int n1, int d1, int n2, int d2, int *numerador, int *denominador){
    *numerador = n1*n2;
    *denominador = d1*d2;
}

void divisao(int n1, int d1, int n2, int d2, int *numerador, int *denominador){
    *numerador = n1*d2;
    *denominador = n2*d1;
}

void simplificar(int *numerador, int *denominador){
    int divisorComum = *numerador > *denominador ? *numerador : *denominador;
    while(divisorComum > 1){
        if(*numerador % divisorComum == 0 && *denominador % divisorComum == 0){
            *numerador = *numerador / divisorComum;
            *denominador = *denominador / divisorComum;

            break;
        }

        divisorComum--;
    }
}

int main(){
    int n, n1, n2, d1, d2;
    char operador;

    int numerador, denominador; //numerador e denominador do resultado final

    scanf("%d",&n);

    for(int i=0; i < n; i++){
        leDados(&n1, &n2, &d1, &d2, &operador);

        switch (operador){
            case '+':
                soma(n1, d1, n2, d2, &numerador, &denominador);
                break;
            
            case '-':
                subtracao(n1, d1, n2, d2, &numerador, &denominador);
                break;

            case '*':
                multiplicacao(n1, d1, n2, d2, &numerador, &denominador);
                break;

            default:
                divisao(n1, d1, n2, d2, &numerador, &denominador);
                break;
        }

        printf("%d/%d = ", numerador, denominador);

        simplificar(&numerador, &denominador);

        printf("%d/%d\n", numerador, denominador);
    }

    return 0;
}