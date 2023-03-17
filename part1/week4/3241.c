#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;
    char entrada[11];

    char num1[5], num2[5];
    int j = 0;
    int cont=0;

    scanf("%d", &n);
    getchar();
    for(int i = 0; i<n; i++){
        fgets(entrada, 11, stdin);
        entrada[strlen(entrada)-1] = '\0';

        if(!strcmp(entrada, "P=NP")){
            printf("skipped\n");
        }
        else{
            cont=0; j=0;
            while(entrada[j] != '+'){
                num1[j] = entrada[j];
                j++;
            }
            num1[j]='\0';
            j++;
            while(entrada[j] != '\0'){
                num2[cont] = entrada[j];
                j++;
                cont++;
            }
            num2[cont]='\0';

            printf("%d\n", (atoi(num1)+atoi(num2)));
        }
    }
}