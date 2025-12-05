//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

int main() {
    int g, p;

    while (1) {
        scanf("%d %d", &g, &p);
        if (g == 0 && p == 0) break;

        int results[105][105];

        for (int i = 0; i < g; i++) {
            for (int j = 0; j < p; j++) {
                scanf("%d", &results[i][j]);
            }
        }

        int s;
        scanf("%d", &s);

        while (s--) {
            int k;
            scanf("%d", &k);

            int points[105];
            for (int i = 0; i < k; i++) {
                scanf("%d", &points[i]);
            }

            int pilotScores[105] = {0};

            for (int i = 0; i < g; i++) {
                for (int j = 0; j < p; j++) {
                    int position = results[i][j];
                    if (position <= k) {
                        pilotScores[j] += points[position - 1];
                    }
                }
            }

            int maxScore = -1;
            for (int i = 0; i < p; i++) {
                if (pilotScores[i] > maxScore) {
                    maxScore = pilotScores[i];
                }
            }

            int firstObj = 1;
            for (int i = 0; i < p; i++) {
                if (pilotScores[i] == maxScore) {
                    if (!firstObj) printf(" ");
                    printf("%d", i + 1);
                    firstObj = 0;
                }
            }
            printf("\n");
        }
    }

    return 0;
}
