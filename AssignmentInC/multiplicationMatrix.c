#include <stdio.h>

int main()
{
  int row, coloumn;
  int row1, coloumn1;

  printf("Enter no of rows of 1st:");
  scanf("%d", &row);

  printf("Enter no of columns of 1st:");
  scanf("%d", &coloumn);

  printf("Enter no of rows of 2nd:");
  scanf("%d", &row1);

  printf("Enter no of columns of 2nd:");
  scanf("%d", &coloumn1);

  int mat1[row][coloumn];
  int mat2[row1][coloumn1];
  int mat3[100][100];

  if (coloumn != row1)
  {
    printf("Multiplication can't be done.");
    return 0;
  }

  printf("Enter 1st matrix element:");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < coloumn; j++)
    {
      scanf("%d", &mat1[i][j]);
    }
  }

  printf("Enter 2nd matrix element:");
  for (int i = 0; i < row1; i++)
  {
    for (int j = 0; j < coloumn1; j++)
    {
      scanf("%d", &mat2[i][j]);
    }
  }
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < coloumn1; j++)
    {
      mat3[i][j] = 0;
      for (int k = 0; k < row1; k++)
      {

        mat3[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }

  printf("the result is:\n");
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < coloumn1; j++)
    {
      printf("\t %d", mat3[i][j]);
    }
    printf("\n");
  }
}