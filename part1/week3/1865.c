#include <stdio.h>
#include <string.h>

int main(){
	int C, N;
	char nome[20];
	
	scanf("%d", &C);
	
	while(C>0){
	    scanf("%s %d", nome, &N);
		
		if(strcmp(nome, "Thor") == 0){
			printf("Y\n");
		}
		else{
			printf("N\n");
		}
		
		nome[0] = '\0';
		C--;
	}
	
	return 0;
}