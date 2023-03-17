#include <stdio.h>

long long int factorial(long long int n){
    if (n == 0 || n == 1){
        return 1;
    }
    
    if(n == 2){
        return n;
    }

    return n * factorial(n - 1);
}

int main(){
    long long int n1, n2;

    while (scanf("%lld %lld", &n1, &n2) != EOF){
        printf("%lld\n", factorial(n1) + factorial(n2));
    }
    

}