#include <stdio.h>
int main()
{
    int a, b, small;
    int n;
    printf("Enter the number of integers to be added : ");
    scanf("%d", &n);
    printf("Enter integers: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    for (int i = 2; i < n; i++)
    {
        if (a < b)
        {
            small = a;
            scanf("%d", &a);
        }
        else
        {
            small = b;
            scanf("%d", &b);
        }
    }
    printf("smallest = %d", small);
    return 0;
}