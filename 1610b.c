//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} node;

node* createNode(int v) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(node** adj, int src, int dest) {
    node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;
}

int temCiclo(int u, node** adj, int* visitado) {
    visitado[u] = 1;

    node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->vertex;
        
        if (visitado[v] == 1) {
            return 1; 
        }
        
        if (visitado[v] == 0) {
            if (temCiclo(v, adj, visitado)) {
                return 1;
            }
        }
        
        temp = temp->next;
    }

    visitado[u] = 2;
    return 0;
}

void freeGraph(node** adj, int n) {
    for (int i = 0; i < n; i++) {
        node* temp = adj[i];
        while (temp) {
            node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(adj);
}

int main() {
    int t, n, m, a, b;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);

        node** adj = (node**)malloc(n * sizeof(node*));
        for (int j = 0; j < n; j++) {
            adj[j] = NULL;
        }

        for (int k = 0; k < m; k++) {
            scanf("%d %d", &a, &b);
            addEdge(adj, a - 1, b - 1); 
        }

        int* visitado = (int*)calloc(n, sizeof(int));
        int encontrouCiclo = 0;

        for (int i = 0; i < n; i++) {
            if (visitado[i] == 0) {
                if (temCiclo(i, adj, visitado)) {
                    encontrouCiclo = 1;
                    break;
                }
            }
        }

        if (encontrouCiclo) printf("SIM\n");
        else printf("NAO\n");

        free(visitado);
        freeGraph(adj, n);
    }

    return 0;
}
