//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

#define MAX 26
int matrix[MAX][MAX];
int visited[MAX];

void dfs(int current)
{
    int i;
    visited[current] = 1;
    for (i = 0; i < MAX; i++)
    {
        if (visited[i] != 1)
        {
            if (matrix[current][i] == 1)
            {
                dfs(i);
            }
        }
    }
}

int main() {
 
    int n, i, j, k, l, vertices, edges;
    int counter, current, printed[MAX];
    char a, b;
    
    scanf( "%d", &n);
    for (i = 0; i < n; i++)
    {
        for (l = 0; l < MAX; l++)
        {
            for (k = 0; k < MAX; k++)
            {
                matrix[l][k] = 0;
            }
        }

        scanf(" %d %d", &vertices, &edges);
        for (j = 0; j < edges; j++)
        {
            scanf(" %c %c", &a, &b);
            matrix[a-97][b-97] = 1;
            matrix[b-97][a-97] = 1;
        }
        
        printf("Case #%d:\n", i + 1);
        for (j = 0; j < MAX; j++)
        {
            visited[j] = 0;
        }
        
        counter = 0;
        
        for (j = 0; j < MAX; j++)
        {
            printed[j] = 0;
        }
        
        for (current = 0; current < vertices; current++)
        {
            if (visited[current] != 1) 
            {
                dfs(current);
                
                for (j = 0; j < MAX; j++)
                {
                    if (visited[j] == 1 && printed[j] != 1)
                    {
                        printf("%c,", j + 97);
                        printed[j] = 1;
                    }
                }
                printf("\n");
                counter++;
            }
        }
        
        printf("%d connected components\n\n", counter);
    }
 
    return 0;
}
