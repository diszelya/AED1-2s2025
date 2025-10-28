//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

int verifycolumn(int board[9][9]) {
  int i, j;
  for (j = 0; j < 9; j++) {
    int seen[10] = {
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0
    };
    for (i = 0; i < 9; i++) {
      int num = board[i][j];
      if (num < 1 || num > 9 || seen[num] == 1) {
        return 1;
      }
      seen[num] = 1;
    }
  }
  return 0;
}

int verifyline(int board[9][9]) {
  int i, j;
  for (i = 0; i < 9; i++) {
    int seen[10] = {
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0
    };
    for (j = 0; j < 9; j++) {
      int num = board[i][j];
      if (num < 1 || num > 9 || seen[num] == 1) {
        return 1;
      }
      seen[num] = 1;
    }
  }
  return 0;
}

int verifysquare(int board[9][9]) {
  int startRow, startCol;
  for (startRow = 0; startRow < 9; startRow += 3) {
    for (startCol = 0; startCol < 9; startCol += 3) {
      int seen[10] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };
      int i, j;
      for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
          int num = board[startRow + i][startCol + j];
          if (num < 1 || num > 9 || seen[num] == 1) {
            return 1;
          }
          seen[num] = 1;
        }
      }
    }
  }
  return 0;
}

int main() {
  int numberofboards, board[9][9], i, j, k;

  scanf("%d", & numberofboards);

  int results[numberofboards];

  for (k = 0; k < numberofboards; k++) {
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        scanf("%d", & board[i][j]);
      }
    }

    int a = verifysquare(board);
    int b = verifyline(board);
    int c = verifycolumn(board);

    if (a == 1 || b == 1 || c == 1) {
      results[k] = 1;
    } else {
      results[k] = 0;
    }
  }

  for (k = 0; k < numberofboards; k++) {
    printf("Instancia %d\n", k + 1);
    if (results[k] == 1) {
      printf("NAO\n\n");
    } else {
      printf("SIM\n\n");
    }
  }
  return 0;
}

