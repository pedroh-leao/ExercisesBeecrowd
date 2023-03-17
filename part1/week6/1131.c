#include <stdio.h>
 
int main() {
    int golGremio, golInter;
    int op, grenais=0, vitInter=0, vitGremio=0, empates=0;

    do
    {
        scanf("%d%d", &golInter, &golGremio);

        grenais++;
        if(golInter>golGremio)
            vitInter++;
        else if(golGremio>golInter)
            vitGremio++;
        else 
            empates++;

        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &op);
    }while (op==1);

    printf("%d grenais\n", grenais);
    printf("Inter:%d\n", vitInter);
    printf("Gremio:%d\n", vitGremio);
    printf("Empates:%d\n", empates);

    if(vitInter>vitGremio)
        printf("Inter venceu mais\n");
    else if(vitGremio>vitInter)
        printf("Gremio venceu mais\n");
    else
        printf("Nao houve vencedor\n");
 
    return 0;
}