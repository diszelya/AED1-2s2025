//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

#define MAX 10000

int queue[MAX];
int dist[MAX];

int reverseInteger(int n) 
{
    int reversed = 0;
    while (n != 0) 
    {
        int remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    return reversed;
}
    
void bfs(int head, int tail, int target)
{
    if (queue[head] == target) 
    {
        printf("%d\n", dist[queue[head]]);
        return;
    }

    int incremented = queue[head] + 1;
    if (incremented < MAX && dist[incremented] == -1)
    {
        queue[tail] = incremented;
        dist[incremented] = dist[queue[head]] + 1;
        tail++;
    }

    int reversed = reverseInteger(queue[head]);
    if (reversed < MAX && dist[reversed] == -1)
    {
        queue[tail] = reversed;
        dist[reversed] = dist[queue[head]] + 1;
        tail++;
    }

    if (head + 1 < tail)
    {
        bfs(head + 1, tail, target);
    }
}
    
int main() {
 
    int i, j, t, a, b, head, tail;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++)
    {    
        for (j = 0; j < MAX; j++)
        {
            queue[j] = 0;
        }
        for (j = 0; j < MAX; j++)
        {
            dist[j] = -1;
        }
        scanf(" %d %d", &a, &b);
        queue[0] = a;
        head = 0; tail = 1; dist[queue[head]] = 0;
        
        bfs(head, tail, b);
    }
    
    return 0;
}
