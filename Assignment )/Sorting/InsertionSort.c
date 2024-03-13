#include <stdio.h>

void insertion_sort_ascending(int *arr, int size) {
    for (int usi = 1; usi < size; usi++) {
        int key = arr[usi];
        int sli = usi - 1;
        while (sli >= 0 && key < arr[sli]) {
            arr[sli + 1] = arr[sli];
            sli--;
        }
        arr[sli + 1] = key;
    }
}

void insertion_sort_descending(int *arr, int size) {
    for (int usi = 1; usi < size; usi++) {
        int key = arr[usi];
        int sli = usi - 1;
        while (sli >= 0 && key > arr[sli]) {
            arr[sli + 1] = arr[sli];
            sli--;
        }
        arr[sli + 1] = key;
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

    insertion_sort_ascending(arr, n);
    printf("Sorted array ascending: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertion_sort_descending(arr, n);
    printf("Sorted array descending: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
