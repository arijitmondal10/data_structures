#include <stdio.h>

int calculateGcd(int X, int Y)
{
  if (Y != 0)
  {
    return calculateGcd(Y, X % Y);
  }
  else
  {
    return X;
  }
}

int gcd_of_array(int arr[], int n) {
    if (n == 1)
        return arr[0];
    return calculateGcd(arr[n - 1], gcd_of_array(arr, n - 1));
}

int main()
{
  int n;
  printf("Enter no of inputs:");
  scanf("%d",&n);
  int arr[n];
  for(int i =0;i<n;i++){
    scanf("%d",&arr[i]);
  }
    
    int result = gcd_of_array(arr, n);
    printf("GCD of the numbers: %d\n", result);

    return 0;
}