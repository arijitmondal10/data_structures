#include<stdio.h>

int main(){
    int row,coloumn;
    
    printf("Enter no of rows:");
    scanf("%d",&row);

    printf("Enter no of columns:");
    scanf("%d",&coloumn);

    int mat1[row][coloumn];
    int mat2[row][coloumn];
    int mat3[100][100];

    printf("Enter 1st matrix element:");
    for(int i=0;i<row;i++){
        for(int j=0;j<coloumn;j++){
            scanf("%d",&mat1[i][j]);
        }
    }

    printf("Enter 2nd matrix element:");
    for(int i=0;i<row;i++){
        for(int j=0;j<coloumn;j++){
            scanf("%d",&mat2[i][j]);
      }
    }

   
    for(int i=0;i<row;i++){
        for(int j=0;j<coloumn;j++){
           mat3[i][j]=0;
           mat3[i][j]= mat1[i][j]-mat2[i][j];
        }
    }

     printf("the result is:\n");
       for(int i=0;i<row;i++){
        for(int j=0;j<coloumn;j++){
           printf("\t %d",mat3[i][j]);
      }
      printf("\n");
    }
}