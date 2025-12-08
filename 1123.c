//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

#define MAX 251
#define INF 999999

int adj[MAX][MAX];
int visited[MAX], dist[MAX];

void dijkstra(int start, int n){
    int i, j, u;
    //clear arrays
    for (i = 0; i < MAX; i++){
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;
    
    //main loop
    for (j = 0; j < n; j++){
        //choose u
        u = -1;
        for (i = 0; i < MAX; i++){
            if (visited[i] == 0){
                u = i; break;
            }
        }
        if (u == -1) break;
        
        for (i = 0; i < MAX; i++){
            if (dist[i] < dist[u]){
                if (visited[i] == 0) u = i;
            }
        }
        
        if (u == INF) break;
        
        visited[u] = 1;
        //relax
        
        for (i = 0; i < MAX; i++){
            if (adj[u][i] != INF){
                if (dist[i] > dist[u] + adj[u][i]){
                    if (visited[i] == 0){
                        dist[i] = adj[u][i] + dist[u];
                    }
                }
            }
        }
    }
}


int main() {
    
    int n, m, c, k;
    int u, v, p;
    int i, j;
    
    
    //main loop
    while (1){
        //input
        scanf(" %d %d %d %d", &n, &m, &c, &k);
        if (n == 0 && m == 0 && c == 0 && k == 0){
            break;
        }
        //clear arrays
        for (i = 0; i < MAX; i++){
                visited[i] = 0;
            for (j = 0; j < MAX; j++){
                adj[i][j] = INF;
            }
        }
        //highways (build graph)
        for (i = 0; i < m; i++){
            scanf(" %d %d %d", &u, &v, &p);
                if (u >= c - 1 || v == u + 1){
                    adj[u][v] = p;
                }
                if (v >= c - 1 || u == v + 1){
                    adj[v][u] = p;
                }
        }
        
        dijkstra(k, n);
        printf("%d\n", dist[c-1]);
    }
    return 0;
}
