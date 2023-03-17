#include <stdio.h>

int main(){
	float M[12][12], soma = 0, media;
	char operation;
	
	scanf("%c", &operation);
	
	for(int i=0; i<12; i++){
		for(int j=0; j<12; j++){
			scanf("%f", &M[i][j]);
		}
	}
	
	int contagem = 1;
	for(int i=1; i<12; i++){
		for(int j=0; j<contagem; j++){
			soma += M[i][j];
		}
		contagem++;
	}
	
	if(operation == 'S'){
		printf("%.1f\n", soma);
	}
	else{
		media = soma / 66;
		printf("%.1f\n", media);
	}
	
	return 0;
}