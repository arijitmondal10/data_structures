#include <stdio.h>
#include <stdlib.h>

int **memoryAllocate(int row, int column)
{
    int **M;
    M = (int **)calloc(row, sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        M[i] = (int *)calloc(column, sizeof(int));
    }

    return M;
}

void inputMatrix(int **mat, int row, int col)
{

    static int i = 0;
    static int j = 0;
    if (j == col)
    {
        i++;
        j = 0;
    }
    if (i == row)
    {
        i = 0;
        return;
    }
    scanf("%d", &mat[i][j]);
    j++;

    inputMatrix(mat, row, col);
}

void AddMat(int **mat1, int **mat2, int **mat3, int row, int col)
{
    static int i = 0;
    static int j = 0;
    if (j == col)
    {
        i++;
        j = 0;
    }
    if (i == row)
    {
        i = 0;
        return;
    }
    mat3[i][j] += mat1[i][j] * mat2[i][j];
    j++;
    AddMat(mat1, mat2, mat3, row, col);
}

void display(int **mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}

void free_memory(int **mat,int row){
    for(int i =0 ; i<row;i++){
        free(mat[i]);
    }
    free(mat);
}

int main()
{
    int row, col;
    printf("Enter Row , Column: \n");
    scanf("%d%d", &row, &col);
    int **mat1, **mat2, **mat3;

    mat1 = memoryAllocate(row, col);
    mat2 = memoryAllocate(row, col);
    mat3 = memoryAllocate(row, col);

    printf("Enter elements for 1st matrix: \n");
    inputMatrix(mat1, row, col);

    printf("Enter elements for 2nd matrix: \n");

    inputMatrix(mat2, row, col);
    AddMat(mat1, mat2, mat3, row, col);

    printf("The matrix is: \n");
    display(mat3, row, col);

    free_memory(mat1,row);
    free_memory(mat2,row);
    free_memory(mat3,row);
}
