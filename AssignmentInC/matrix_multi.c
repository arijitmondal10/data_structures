#include <stdio.h>
#include <stdlib.h>

int **allocate_memory(int row, int col)
{
    int **mat;
    mat = (int **)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        mat[i] = (int *)calloc(col, sizeof(int));
    }
    return mat;
}

void input_matrix(int **mat, int row, int col)
{
    printf("Enter the matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void display_matrix(int **mat, int row, int col)
{
    printf("Matrix:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void free_memory(int **mat, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(mat[i]);
    }
    free(mat);
}

void multiply(int **A, int **B, int **C, int row, int col, int row2, int col2)
{
    static int i = 0, j = 0, k = 0;

    if (i >= row)
        return;
    if (j < col2)
    {
        if (k < col)
        {
            C[i][j] += A[i][k] * B[k][j];
            k++;
            multiply(A, B, C, row, col, row2, col2);
        }
        k = 0;
        j++;
        multiply(A, B, C, row, col, row2, col2);
    }
    j = 0;
    i++;
    multiply(A, B, C, row, col, row2, col2);
}

int main()
{
    int **mat1, **mat2, **mat3, row, col, row2, col2;
    printf("Enter the number of rows and columns of the 1st matrix: ");
    scanf("%d%d", &row, &col);
    printf("Enter the number of rows and columns of the 2nd matrix: ");
    scanf("%d%d", &row2, &col2);

    mat1 = allocate_memory(row, col);
    mat2 = allocate_memory(row2, col2);
    mat3 = allocate_memory(row, col2);

    printf("Enter elements of first matrix: \n");
    input_matrix(mat1, row, col);

    printf("Enter elements of second matrix: \n");
    input_matrix(mat2, row2, col2);

    multiply(mat1, mat2, mat3, row, col, row2, col2);

    printf("Multiplication of the matrices: \n");
    display_matrix(mat3, row, col2);

    free_memory(mat1, row);
    free_memory(mat2, row2);
    free_memory(mat3, row);

    return 0;
}