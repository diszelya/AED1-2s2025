//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {
    int value;
    struct tNode *left;
    struct tNode *right;
} tNode;

typedef tNode *pNode;

pNode insert(pNode root, int v) {
    if (root == NULL) {
        root = (pNode)malloc(sizeof(tNode));
        root->value = v;
        root->left = NULL;
        root->right = NULL;
        return (root);
    }

    if (v < root->value) {
        root->left = insert(root->left, v);
    } else if (v >= root->value) {
        root->right = insert(root->right, v);
    }

    return (root);
}

void preorder(pNode root) {
    if (root == NULL) {
        return;
    }
    printf(" %d", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(pNode root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf(" %d", root->value);
    inorder(root->right);
}

void postorder(pNode root) {
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->value);
}

pNode freetree(pNode root) {
    if (root == NULL) {
        return NULL;
    }
    root->left = freetree(root->left);
    root->right = freetree(root->right);
    free(root);
    return NULL;
}

int main() {
    int c, n, i, value, case_num;
    pNode root = NULL;

    scanf("%d", &c);

    for (case_num = 1; case_num <= c; case_num++) {
        scanf("%d", &n);
        root = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &value);
            root = insert(root, value);
        }

        printf("Case %d:\n", case_num);
        
        printf("Pre.:");
        preorder(root);
        printf("\n");

        printf("In..:");
        inorder(root);
        printf("\n");

        printf("Post:");
        postorder(root);
        printf("\n\n");

        root = freetree(root);
    }

    return 0;
}
