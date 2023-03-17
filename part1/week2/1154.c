#include <stdio.h>
 
int main() {
    int soma = 0, totalAges = 0, age;
    double media;
    
    scanf("%d", &age);
    
    while(age >= 0){
        totalAges++;
        soma+=age;

        scanf("%d", &age);
    }
    
    media = soma / (float)totalAges;
    printf("%.2lf\n", media);
 
    return 0;
}