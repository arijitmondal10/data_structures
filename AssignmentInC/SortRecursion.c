#include <stdio.h>

void divide(int arr[], int si, int ei);
void conquer(int arr[], int si, int mid, int ei);
void print_array(int arr[], int size);

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter array elements: \n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    divide(arr, 0, size - 1);
    print_array(arr, size);
    return 0;
}

void divide(int arr[], int si, int ei)
{
    if (si == ei)
    {
        return;
    }

    int mid = si + (ei - si) / 2;

    divide(arr, si, mid);
    divide(arr, mid + 1, ei);

    conquer(arr, si, mid, ei);
}

void conquer(int arr[], int si, int mid, int ei)
{
    int merged[ei - si + 1];

    int index1 = si;
    int index2 = mid + 1;
    int x = 0;

    while (index1 <= mid && index2 <= ei)
    {
        if (arr[index1] <= arr[index2])
        {
            merged[x] = arr[index1];
            index1++;
        }
        else
        {
            merged[x] = arr[index2];
            index2++;
        }
        x++;
    }

    while (index1 <= mid)
    {
        merged[x] = arr[index1];
        x++;
        index1++;
    }

    while (index2 <= ei)
    {
        merged[x] = arr[index2];
        x++;
        index2++;
    }

    for (int i = si, x = 0; i <= ei; i++, x++)
    {
        arr[i] = merged[x];
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}