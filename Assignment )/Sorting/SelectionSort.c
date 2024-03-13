#include <stdio.h>

void selection_sort_ascending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int si = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[si] > arr[j]) {
                int temp = arr[si];
                arr[si] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selection_sort_descending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int si = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[si] < arr[j]) {
                int temp = arr[si];
                arr[si] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    selection_sort_ascending(arr, n);
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selection_sort_descending(arr, n);
    printf("Sorted array in descending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
