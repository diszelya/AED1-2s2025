//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#define MAX 21

int reserves[MAX];

int main() {
    int b, n, d, c, v;
    int i;
    char possible;
    
    while (scanf("%d %d", &b, &n) && (b != 0 || n != 0)) {
        
        for (i = 1; i <= b; i++) {
            scanf("%d", &reserves[i]);
        }
        
        for (i = 0; i < n; i++) {
            scanf("%d %d %d", &d, &c, &v);
            reserves[d] -= v;
            reserves[c] += v;
        }

        possible = 'S';
        for (i = 1; i <= b; i++) {
            if (reserves[i] < 0) {
                possible = 'N';
                break;
            }
        }
        
        printf("%c\n", possible);
    }
    return 0;
}
