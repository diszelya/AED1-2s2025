//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
 
#define MAX 50001
#define MAXID 100001

int main() {
    int m, n, qEnd, queue[MAX], left[MAXID], i, j;
    
    scanf("%d", &n);
    
    qEnd = n;
    
    for (i = 0; i < n; i++){
        scanf("%d", &queue[i]);
    }
    
    scanf("%d", &m);
    int dropouts[m];
    
    for (i = 0; i < m; i++)
    {
        scanf("%d", &dropouts[i]);
    }
    
    for (i = 0; i < MAXID; i++)
    {
        left[i] = 0;
    }
    
    for (i = 0; i < m; i++)
    {
        left[dropouts[i]] = 1;
    }
    
    
    int first = 0;
    
    for (i = 0; i < qEnd; i++)
    {
        if (left[queue[i]] != 1)
        {
            if (first == 1)
            {
                printf(" %d", queue[i]);
            }
            if (first == 0)
            {
                printf("%d", queue[i]);
                first = 1;
            }
        }
    }
    printf("\n");
    return 0;
}
