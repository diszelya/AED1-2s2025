//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <string.h>

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        int adj[25][25];
        int degrees[25];
        char results[25][2500];
        char name[25];

        for (int i = 1; i <= n; i++) {
            degrees[i] = 0;
            results[i][0] = '\0';
        }

        for (int i = 1; i <= n; i++) {
            int friendId;
            while (scanf("%d", &friendId) && friendId != 0) {
                adj[i][degrees[i]++] = friendId;
            }
        }

        int p;
        while (scanf("%d", &p) && p != 0) {
            int t1, t2;
            char a1[25], a2[25], a3[25];
            
            scanf("%d %d %s %s %s", &t1, &t2, a1, a2, a3);

            int visited[25] = {0};
            int queue[25];
            int front = 0, rear = 0;

            queue[rear++] = p;
            visited[p] = 1;

            while (front < rear) {
                int u = queue[front++];
                
                for (int k = 0; k < degrees[u]; k++) {
                    int v = adj[u][k];
                    if (!visited[v]) {
                        visited[v] = 1;
                        queue[rear++] = v;
                    }
                }
                
            }

            for (int i = 1; i <= n; i++) {
                int sent = 0;
                
                if (visited[i]) {
                    sent = degrees[i];
                }


                if (sent < t1) {
                    strcat(results[i], a1);
                } 
                else if (sent < t2) {
                    strcat(results[i], a2);
                } 
                else {
                    strcat(results[i], a3);
                }
                strcat(results[i], " ");
            }
            
        }

        for (int i = 1; i <= n; i++) {
            scanf("%s", name);
            printf("%s: %s\n", name, results[i]);
        }
    }

    return 0;
}
