#include <stdio.h>
#include <stdlib.h>

int **memeory_Allocation(int n){
    int **M,i;
    M = (int**)calloc(n,sizeof(int*));
    for(int i =0;i<n;i++){
        M[i]=(int*)calloc(n,sizeof(int));
    }
    return M;
}
void inputMatrix(int** mat, int n) {
    printf("Enter the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}
int addition_Matrix(int rs,int cs,int re,int ce,int **A,int **B,int **C){
    if(re-rs==1){
        return C[rs][cs]= A[rs][cs]+B[rs][cs];

    }
    addition_Matrix(rs,cs,(rs+re)/2,(cs+ce)/2,A,B,C);
    addition_Matrix(rs,(cs+ce)/2,(rs+re)/2,ce,A,B,C);
    addition_Matrix((rs+re)/2,cs,re,(cs+ce)/2,A,B,C);
    addition_Matrix((rs+re)/2,(cs+ce)/2,re,ce,A,B,C);
}
void displayMatrix(int **mat, int n) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {

    int n,i,j,**A,**B,**C;
    printf("Enter the size of matrix of orden n:");
    scanf("%d",&n);

    A = memeory_Allocation(n);
    B= memeory_Allocation(n);
    C = memeory_Allocation(n);

    inputMatrix(A,n);
    inputMatrix(B,n);

    addition_Matrix(0,0,n,n,A,B,C);

    printf("\nFirst\n");
    displayMatrix(A,n);
    printf("\nSecond\n");
    displayMatrix(B,n);
    printf("\nResult\n");
    displayMatrix(C,n);
}