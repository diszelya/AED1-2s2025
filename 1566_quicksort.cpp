//RA: 177065 UNIFESP AED1 2s2025

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
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

        quicksort(arr, 0, n - 1);

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
