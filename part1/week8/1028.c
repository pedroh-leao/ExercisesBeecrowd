#include <stdio.h>

int mdc(int num1, int num2) {

    int resto;

    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}

int main(){
    int n, f1, f2;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &f1, &f2);

        printf("%d\n", mdc(f1, f2));
    }    

    return 0;
}