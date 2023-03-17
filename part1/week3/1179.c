#include <stdio.h>

int main(){
	int v[15], par[5], impar[5];
	
	for(int i = 0; i<15; i++){
		scanf("%d", &v[i]);
	}
	
	int posicaoPar = 0, posicaoImpar = 0;
	for(int i = 0; i<15; i++){
		if(v[i]%2==0){
			par[posicaoPar] = v[i];
			
			if(posicaoPar == 4){
				for(int j = 0; j<5; j++){
					printf("par[%d] = %d\n", j, par[j]);
				}
				posicaoPar = 0;
			}
			else{
				posicaoPar++;
			}
		}
		else{
			impar[posicaoImpar] = v[i];
			
			if(posicaoImpar == 4){
				for(int j = 0; j<5; j++){
					printf("impar[%d] = %d\n", j, impar[j]);
				}
				posicaoImpar = 0;
			}
			else{
				posicaoImpar++;
			}
		}
	}
	
	for(int i = 0; i<posicaoImpar; i++){
		printf("impar[%d] = %d\n", i, impar[i]);
	}
	
	for(int i = 0; i<posicaoPar; i++){
		printf("par[%d] = %d\n", i, par[i]);
	}
	
	return 0;
}