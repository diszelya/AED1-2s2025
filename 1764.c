//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

Edge edges[50005];
int parent[40005];

int compare(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

int main() {
    int m, n;

    while (scanf("%d %d", &m, &n) && (m != 0 || n != 0)) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }

        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }

        qsort(edges, n, sizeof(Edge), compare);

        int totalDistance = 0;
        
        for (int i = 0; i < n; i++) {
            int rootU = find(edges[i].u);
            int rootV = find(edges[i].v);

            if (rootU != rootV) {
                parent[rootU] = rootV;
                totalDistance += edges[i].w;
            }
        }

        printf("%d\n", totalDistance);
    }

    return 0;
}
