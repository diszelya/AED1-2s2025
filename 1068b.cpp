//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tNode {
    struct tNode *next;
    char content;
} tNode;

typedef tNode *pNode;

pNode push(pNode top){
    pNode new = (pNode)malloc(sizeof(tNode));
    new -> content = '(';
    new -> next = top;
    return(new);
}

pNode pop(pNode top){
    if (top != NULL){
        pNode aux = top -> next;
        free(top);
        return(aux);
    }
    return(NULL);
}

void freestack(pNode top){
    pNode aux;
    while (top != NULL){
        aux = top->next;
        free(top);
        top = aux;
    }
}

int main(){
    int i;
    pNode top = NULL;
    char expression[1001];

    while (scanf("%s", expression) == 1) {
        int error_found = 0; 
        for (i = 0; expression[i] != '\0'; i++){
            
            if (expression[i] == '('){
                top = push(top);
            }
            else if (expression[i] == ')'){
                if (top == NULL){
                    error_found = 1;
                    break; 
                }
                else {
                    top = pop(top);
                }
            }
        }
        if (error_found == 1 || top != NULL) {
            printf("incorrect\n");
        }
        else {
            printf("correct\n");
        }
        freestack(top);
        top = NULL;
    }
    return 0;
}
