//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

#define MAX 501
#define INF 999999

int adj[MAX][MAX];
int visited[MAX];
int dist[MAX];

void dijkstra(int start) {
    int i, j, closestTown;

    for (i = 0; i < MAX; i++) {
        closestTown = -1;

        for (j = 0; j < MAX; j++) {
            if (visited[j] == 0 && dist[j] != INF) {
                if (closestTown == -1 || dist[j] < dist[closestTown]) {
                    closestTown = j;
                }
            }
        }

        if (closestTown == -1) break;

        visited[closestTown] = 1;

        for (j = 0; j < MAX; j++) {
            if (adj[closestTown][j] != INF) {
                if (dist[j] > dist[closestTown] + adj[closestTown][j]) {
                    dist[j] = dist[closestTown] + adj[closestTown][j];
                }
            }
        }
    }
}

int sameCountry(int a, int b) {
    if (adj[b][a] != INF) {
        if (adj[a][b] != INF) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, e, k, x, y, o, d, h;
    int i, j;

    while (scanf(" %d %d", &n, &e) != EOF) {
        if (n == 0 && e == 0) break;

        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                adj[i][j] = INF;
            }
        }

        for (i = 0; i < e; i++) {
            scanf(" %d %d %d", &x, &y, &h);
            adj[x][y] = h;
        }

        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                if (sameCountry(i, j) == 1) {
                    adj[i][j] = 0;
                }
            }
        }

        scanf("%d", &k);
        for (i = 0; i < k; i++) {
            for (j = 0; j < MAX; j++) {
                visited[j] = 0;
                dist[j] = INF;
            }
            scanf(" %d %d", &o, &d);
            
            dist[o] = 0;
            dijkstra(o);
            
            if (dist[d] != INF) {
                printf("%d\n", dist[d]);
            } else {
                printf("Nao e possivel entregar a carta\n");
            }
        }
        printf("\n");
    }

    return 0;
}
