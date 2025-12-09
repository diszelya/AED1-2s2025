//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u;
    int v;
    int weight;
} Edge;

int parent[200005];
Edge edges[200005];

int findSet(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = findSet(parent[i]);
}

int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

int main() {
    int m, n;

    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
            totalCost += edges[i].weight;
        }

        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }

        qsort(edges, n, sizeof(Edge), compareEdges);

        int mstCost = 0;

        for (int i = 0; i < n; i++) {
            int rootU = findSet(edges[i].u);
            int rootV = findSet(edges[i].v);

            if (rootU != rootV) {
                parent[rootU] = rootV;
                mstCost += edges[i].weight;
            }
        }

        printf("%d\n", totalCost - mstCost);
    }

    return 0;
}
