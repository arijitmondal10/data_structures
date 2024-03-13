
#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int lcm_of_array(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    return lcm(arr[n - 1], lcm_of_array(arr, n - 1));
}

int main()
{
    int n;
    printf("Enter no of inputs:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("LCM of the numbers: %d\n", lcm_of_array(arr, n));

    return 0;
}