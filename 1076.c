//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

int main()
{
    int testCases;
    scanf("%d", &testCases);

    while (testCases > 0)
    {
        int startNode;
        scanf("%d", &startNode);

        int vertices, edges;
        scanf("%d %d", &vertices, &edges);

        int adjMatrix[50][50];
        int x, y;
        
        for (x = 0; x < 50; x++)
        {
            for (y = 0; y < 50; y++)
            {
                adjMatrix[x][y] = 0;
            }
        }

        int uniqueEdges = 0;
        int i;
        
        for (i = 0; i < edges; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);

            if (adjMatrix[u][v] == 0)
            {
                adjMatrix[u][v] = 1;
                adjMatrix[v][u] = 1;
                uniqueEdges++;
            }
        }

        printf("%d\n", uniqueEdges * 2);
        testCases--;
    }

    return 0;
}
