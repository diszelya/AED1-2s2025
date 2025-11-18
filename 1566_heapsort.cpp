//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int nc, n, i;
    int *arr;

    scanf("%d", &nc);

    while (nc > 0) {
        scanf("%d", &n);

        arr = (int *)malloc(n * sizeof(int));

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        heapsort(arr, n);

        if (n > 0) {
            printf("%d", arr[0]);
            for (i = 1; i < n; i++) {
                printf(" %d", arr[i]);
            }
        }
        printf("\n");

        free(arr);
        nc--;
    }

    return 0;
}
