//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>

#include <stdlib.h>

int main() {
  int i, N;
  scanf("%d", & N);
  int * p = (int * ) malloc(sizeof(int) * N);

  for (i = 0; i < N; i++) {
    scanf("%d", p + i);
  }

  int number = * p, count = 0;
  for (i = 0; i < N; i++) {
    if ( * (p + i) < number) {
      number = * (p + i);
      count = i;
    }
  }

  printf("Menor valor: %d\n", number);
  printf("Posicao: %d\n", count);
  free(p);
  return 0;
}
