#include <stdio.h>

void fibo(long long *vetor){
	vetor[0] = 0;
	vetor[1] = 1;
	
	for(int i=2; i<61; i++){
		vetor[i] = vetor[i-1] + vetor[i-2];
	}
}
 
int main() {
    int n, x;
    scanf("%d", &n);
     long long vetor[61];
     fibo(vetor);
     
     for(int i=0; i<n; i++){
         scanf("%d", &x);
         printf("Fib(%d) = %lld\n", x, vetor[x]);
     }
 
    return 0;
}