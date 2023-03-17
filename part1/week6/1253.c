#include <stdio.h>
#include <string.h>

int main() {
    int n; //qtd de casos de teste
    char str[50];
    int deslocamento, tamStr;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%s", str);
        scanf("%d", &deslocamento);

        tamStr = strlen(str);

        for (int j = 0; j < tamStr; j++)
        {
            if(str[j] < 65+deslocamento){
                //91 - (deslocamento - (str[j] - 65))
                str[j] = 91 - (deslocamento - (str[j] - 65));
            }
            else
                str[j] -= deslocamento;
        }
        
        printf("%s\n", str);
    }
    
    return 0;
}