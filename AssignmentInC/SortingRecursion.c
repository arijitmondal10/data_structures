#include <stdio.h>

void join(int arr[], int s, int mid, int e)
{
    int newArr[e - s + 1];
    int idx1 = s;
    int idx2 = mid + 1;

    int i = 0;
    while (idx1 <= mid && idx2 <= e)
    {
        if (arr[idx1] >= arr[idx2])
        {
            newArr[i] = arr[idx2];
            idx2++;
        }
        else
        {
            newArr[i] = arr[idx1];
            idx1++;
        }
        i++;
    }
    while (idx1 <= mid)
    {
        newArr[i] = arr[idx1];
        i++;
        idx1++;
    }

    while (idx2 <= e)
    {
        newArr[i] = arr[idx2];
        i++;
        idx2++;
    }

    for (int j = s, k = 0; j <= e; j++, k++)
    {
        arr[j] = newArr[k];
    }
}

void divide(int arr[], int s, int e)
{
    if (s == e)
    {
        return;
    }
    int mid = (s + (e - s)) / 2;
    divide(arr, s, mid);
    divide(arr, mid + 1, e);
    join(arr, s, mid, e);
}

int main()
{
    int size;
    printf("Enter size:");
    scanf("%d", &size);
    int arr[size];

    printf("Enter elements:");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    divide(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}