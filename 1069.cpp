//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    struct node *next;
    char value;
} tNode;

typedef tNode *pNode;

pNode getstack(pNode stack){
    while(stack != NULL){
        pNode temp = stack;
        stack = stack->next;
        free(temp);
    }

    pNode head = NULL;
    pNode tail = NULL;
    char c;

    while(scanf("%c", &c) == 1 && c != '\n'){
        pNode newNode = (pNode)malloc(sizeof(tNode));
        if (newNode == NULL) exit(1); 
        newNode->value = c;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

pNode removedots(pNode stack){
    pNode curr = stack;
    pNode prev = NULL;
    pNode head = stack;

    while(curr != NULL){
        if(curr->value == '.'){
            pNode toDelete = curr;
            if(prev == NULL){
                head = curr->next;
                curr = head;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }
            free(toDelete);
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int countdiamonds(pNode stack){
    int count = 0;
    int pairFound = 1; 

    while(pairFound){
        pairFound = 0;
        pNode curr = stack;
        pNode prev = NULL;
        pNode head = stack;

        while(curr != NULL && curr->next != NULL){
            if(curr->value == '<' && curr->next->value == '>'){
                count++;
                pairFound = 1;
                
                pNode first = curr;
                pNode second = curr->next;

                if(prev == NULL){
                    head = second->next;
                    curr = head;
                } else {
                    prev->next = second->next;
                    curr = prev->next;
                }

                free(first);
                free(second);
                
                stack = head; 
                break; 
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    }

    while(stack != NULL){
        pNode temp = stack;
        stack = stack->next;
        free(temp);
    }

    return count;
}

int main(){
    int i, n, d;
    pNode stack = NULL; 
    
    scanf("%d", &n);
    getc(stdin); 

    for (i = 0; i < n; i++){
        stack = getstack(stack);
        stack = removedots(stack);
        d = countdiamonds(stack);
        printf("%d\n", d);
        stack = NULL; 
    }
    
    return 0;
}
