//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int first_print = 1; 

typedef struct tNode{
    struct tNode *left;
    struct tNode *right;
    char content;
} tNode;

typedef tNode *pNode;

pNode insert(char v, pNode root){
    if (root == NULL){
        pNode new_node = (pNode)malloc(sizeof(tNode));
        if (new_node == NULL) { 
            return NULL; 
        }
        
        new_node->content = v;
        new_node->left = NULL;
        new_node->right = NULL;
        
        return new_node;
    }
    
    if (v < root->content){
        root->left = insert(v, root->left); 
    } else if (v > root->content){
        root->right = insert(v, root->right); 
    }

    return root;
}

int search(char v, pNode root) {
    if (root == NULL) {
        return 1;
    }
    if (v == root->content) {
        return 0;
    }
    if (v < root->content) {
        return search(v, root->left);
    }
    return search(v, root->right);
}

void pInfix(pNode root){
    if (root == NULL) return;
    
    pInfix(root->left);
    
    if (first_print) {
        printf("%c", root->content);
        first_print = 0;
    } else {
        printf(" %c", root->content);
    }
    
    pInfix(root->right);
}

void pPrefix(pNode root){
    if (root == NULL) return;
    
    if (first_print) {
        printf("%c", root->content);
        first_print = 0;
    } else {
        printf(" %c", root->content);
    }
    
    pPrefix(root->left);
    pPrefix(root->right);
}

void pPostfix(pNode root){
    if (root == NULL) return;
    
    pPostfix(root->left);
    pPostfix(root->right);
    
    if (first_print) {
        printf("%c", root->content);
        first_print = 0;
    } else {
        printf(" %c", root->content);
    }
}

void destroyTree(pNode root) {
    if (root == NULL) return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

int main(){
    char command[7]; 
    char v;
    pNode root = NULL;
    
    while (scanf("%s", command) != EOF){
        
        if (strcmp(command, "I") == 0){
            scanf(" %c", &v); 
            root = insert(v, root);
        }
        
        else if (strcmp(command, "P") == 0) {
            scanf(" %c", &v); 
            if (search(v, root) == 0) {
                printf("%c existe\n", v);
            } else {
                printf("%c nao existe\n", v);
            }
        }
        
        else if (strcmp(command, "INFIXA") == 0){
            first_print = 1;
            pInfix(root);
            printf("\n");
        }
        else if (strcmp(command, "PREFIXA") == 0){
            first_print = 1;
            pPrefix(root);
            printf("\n");
        }
        else if (strcmp(command, "POSFIXA") == 0){
            first_print = 1;
            pPostfix(root);
            printf("\n");
        }
    }
    
    destroyTree(root);
    
    return 0;
}
