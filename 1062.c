//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        while (1) {
            int wagonOrder[1005];
            
            scanf("%d", &wagonOrder[0]);
            if (wagonOrder[0] == 0) {
                printf("\n");
                break;
            }

            for (int i = 1; i < n; i++) {
                scanf("%d", &wagonOrder[i]);
            }

            int station[1005];
            int top = 0;
            int currentIncoming = 1;
            int possible = 1;

            for (int i = 0; i < n; i++) {
                int desiredCar = wagonOrder[i];

                while (1) {
                    if (top > 0 && station[top - 1] == desiredCar) {
                        top--;
                        break;
                    }
                    else if (currentIncoming <= n) {
                        station[top] = currentIncoming;
                        top++;
                        currentIncoming++;
                    }
                    else {
                        possible = 0;
                        break;
                    }
                }
                
                if (possible == 0) break;
            }

            if (possible) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
