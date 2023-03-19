#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    struct cel *next;
    char c;
}Cel;

typedef struct {
    Cel *head;
} Stack;

void startStack(Stack *pStack){
    pStack->head = (Cel *) malloc(sizeof(Cel));
    pStack->head->next = NULL;
}

int stackIsEmpty(Stack * pStack){
    return (pStack->head->next == NULL);
}

void push(Stack *pStack, char c){
    Cel *aux = (Cel *) malloc(sizeof(Cel));

    aux->c = c;
    aux->next = pStack->head->next;
    pStack->head->next = aux;
}

int pop(Stack *pStack){
    if(stackIsEmpty(pStack))
        return 0;

    Cel *aux;
    aux = pStack->head->next;

    pStack->head->next = aux->next;
    free(aux);
    return 1;
}

void finishStack(Stack *pStack){
    Cel * current = pStack -> head;
    Cel * next = current->next;
    
    while (next != NULL){
        free(current);
        current = next;
        next = next -> next;
    }
    free(current);
}

char topStack(Stack *pStack){ //returns the top of the stack
    if(stackIsEmpty(pStack))
        return '-';

    return pStack->head->next->c;
}

int main(){
    char rna[301];
    Stack stackRna;
    int sum;
    int length;

    while (scanf("%s", rna) != EOF) {
        startStack(&stackRna);
        sum = 0;
        length = strlen(rna);

        for (int i = 0; i < length; ++i) {
            if (stackIsEmpty(&stackRna))
                push(&stackRna, rna[i]);

            else {
                if ((topStack(&stackRna) == 'B' && rna[i] == 'S') || (topStack(&stackRna) == 'S' && rna[i] == 'B')) {
                    pop(&stackRna);
                    sum++;
                } 
                else if ((topStack(&stackRna) == 'C' && rna[i] == 'F') || (topStack(&stackRna) == 'F' && rna[i] == 'C')){
                    pop(&stackRna);
                    sum++;
                }
                else
                    push(&stackRna, rna[i]);
            
            }
        }
        finishStack(&stackRna);

        printf("%d\n", sum);
    }

    return 0;
}