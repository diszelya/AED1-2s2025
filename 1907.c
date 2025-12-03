//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

#define MAX 1025

typedef struct {
    int y;
    int x;
} Position;

char map[MAX][MAX];
int n, m;
int top = 0;
Position stack[MAX * MAX];

int validPixel(int i, int j)
{
    if (j < 0 || i < 0 || j >= m || i >= n)
    {
        return 1;
    }
    if (map[i][j] != '.')
    {
        return 1;
    }
    return 0;
}

void dfs(int startI, int startJ)
{
    top = 0;
    stack[top].y = startI;
    stack[top].x = startJ;
    top++;
    
    map[startI][startJ] = 'c';
    
    int di[] = {-1, 0, 1, 0};
    int dj[] = {0, -1, 0, 1};

    while (top > 0)
    {
        int i = stack[top - 1].y;
        int j = stack[top - 1].x;
        top--;

        for (int k = 0; k < 4; k++)
        {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (validPixel(ni, nj) == 0)
            {
                map[ni][nj] = 'c';
                stack[top].y = ni;
                stack[top].x = nj;
                top++;
            }
        }
    }
}

int main()
{
    int i, j, s = 0;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++)
    {
        scanf("%s", map[i]);
    }
   
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (map[i][j] == '.')
            {
                s++;
                dfs(i, j);
            }
        }
    }
   
    printf("%d\n", s);
    return 0;
}
