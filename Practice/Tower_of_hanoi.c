#include <stdio.h>

void towerOfHanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf(" disk %d: %c -> %c\n", n, a, c);
        return;
    }
    towerOfHanoi(n - 1, a, c, b);
    printf("disk%d :%c ->%c\n", n, a, c);
    towerOfHanoi(n - 1, b, a, c);
}

int main()
{
    towerOfHanoi(4, 'A', 'B', 'C');
    return 0;
}