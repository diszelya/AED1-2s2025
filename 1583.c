//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

char map[60][60];
int row, col;

void spread(int r, int c) {
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr >= 0 && nr < row && nc >= 0 && nc < col && map[nr][nc] == 'A') {
            map[nr][nc] = 'T';
            spread(nr, nc);
        }
    }
}

int main() {
    while (scanf("%d %d", &row, &col) && (row || col)) {
        for (int i = 0; i < row; i++)
            scanf("%s", map[i]);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (map[i][j] == 'T')
                    spread(i, j);
            }
        }

        for (int i = 0; i < row; i++)
            printf("%s\n", map[i]);
        printf("\n");
    }

    return 0;
}
