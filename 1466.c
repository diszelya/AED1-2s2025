//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>

typedef struct tNode {
    int val;
    struct tNode *left;
    struct tNode *right;
} tNode;
typedef tNode *pNode;


pNode createNode(int val) {
    pNode new = (pNode)malloc(sizeof(tNode));
    new->val = val;
    new->left = NULL;
    new->right = NULL;
    return new;
}

pNode insert(pNode root, int val){
    if (root == NULL) return createNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

void bfs(pNode root){
    if (root == NULL) return;

    pNode queue[1000];
    int head = 0, tail = 0;

    queue[tail++] = root;
    int first = 1;

    while (head < tail){
        pNode current = queue[head++];

        if (!first) printf(" ");
        printf("%d", current->val);
        first = 0;

        if (current->left) queue[tail++] = current->left;
        if (current->right) queue[tail++] = current->right;
    }
    printf("\n");
}

void freeTree(pNode root){
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
    int C, N, val;
    scanf("%d", &C);

    for (int i = 1; i <= C; i++){
        scanf("%d", &N);
        pNode root = NULL;

        for (int j = 0; j < N; j++){
            scanf("%d", &val);
            root = insert(root, val);
        }

        printf("Case %d:\n", i);
        bfs(root);
        printf("\n");

        freeTree(root);
    }
    return 0;
}
