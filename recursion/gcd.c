#include <stdio.h>
#include <stdlib.h>

//gcd for two numbers
int gcd(int n1, int n2)
{
    int rem = n1 % n2;
    if (rem != 0)
    {
        return gcd(n2, rem);
    }
    return n2;
}

//gcd for n numbers 
int Gcd_of_Nnumbers(int *arr, int i, int a, int b, int n)
{
    int r = a % b;
    if (r == 0 && i == n - 1)
    {
        return b;
    }
    else if (r == 0)
    {
        return Gcd_of_Nnumbers(arr, i + 1, arr[i + 1], b, n);
    }
    return Gcd_of_Nnumbers(arr, i, b, r, n);
}

int main()
{
    // int n1,n2;
    // printf("Enter Two Numbers:");
    // scanf("%d%d",&n1,&n2);
    // printf("%d",gcd(n1,n2));

    int size;
    printf("Enter The size:");
    scanf("%d", &size);
    int *arr = (int *)calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Gcd: %d ", Gcd_of_Nnumbers(arr, 1, arr[0], arr[1], size));

    return 0;
}