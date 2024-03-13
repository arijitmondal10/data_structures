#include<stdio.h>

int main()
{
    int arr[100];
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

int max;
max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    printf("%d", max);

    return 0;
}