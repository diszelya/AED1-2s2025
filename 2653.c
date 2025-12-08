//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tNode{
    struct tNode *left;
    struct tNode *right;
    char *string;
} tNode;

typedef tNode *pNode;

pNode insert(pNode root, char *string){
    if (root == NULL){
        pNode newNode = (pNode)malloc(sizeof(tNode));
        newNode->string = (char *)malloc(strlen(string) + 1);
        strcpy(newNode->string, string);
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (strcmp(string, root->string) > 0){
        root->right = insert(root->right, string);
    }
    else if (strcmp(string, root->string) < 0){
        root->left = insert(root->left, string);
    }
    return root;
}

int count(pNode root){
    if (root == NULL){
        return 0;
    }
    else {
        return 1 + count(root->left) + count(root->right);
    }
}

int main() {
    char s[1000005];
    int k;
    pNode root = NULL;
    
    while (scanf("%s", s) != EOF){
        root = insert(root, s);
    }
    
    k = count(root);
    printf("%d\n", k);

    return 0;
}
