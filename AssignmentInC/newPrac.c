// #include<stdio.h>
// #include<stdlib.h>

// int **memoryAllocate(int row, int column)
// {
//     int **M;
//     M = (int **)calloc(row, sizeof(int *));
//     for (int i = 0; i < row; i++)
//     {
//         M[i] = (int *)calloc(column, sizeof(int));
//     }

//     return M;
// }

// void inputMat(int **mat,int r,int c){
//     static int i = 0;
//     static int j =0;
//     if(j==c){
//         i++;
//         j=0;
//     }
//     if(i= r){
//         i=0;
//         return;
//     }
//     scanf("%d",&mat[i][j]);
//     j++;
//     inputMat(mat,r,c);
// }

// void multiplyMat(int **mat1,int **mat2,int **mat3,int r,int c){
//       static int i = 0;
//     static int j =0;
//     if(j==c){
//         i++;
//         j=0;
//     }
//     if(i= r){
//         i=0;
//         return;
//     }

//     mat3[i][j]+= mat1[i][j]+mat2[i][j];
//     j++;
//     multiplyMat(mat1,mat2,mat3,r,c);
// }

// void display(int **mat,int row,int col){
//     for(int i =0;i<row;i++){
//         for(int j = 0;j<col;j++){
//             printf("%d \t",mat[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main(){
//     int r,c;
//     printf("Enter:");
//     scanf("%d%d",&r,&c);

//     int **mat1;
//     int **mat2;
//     int **mat3;

//     mat1=memoryAllocate(r,c);
//      mat2=memoryAllocate(r,c);
//       mat3=memoryAllocate(r,c);

//       inputMat(mat1,r,c);
//       inputMat(mat2,r,c);
//       multiplyMat(mat1,mat2,mat3,r,c);
//       display(mat3,r,c);

// }

#include<stdio.h>
#include<stdlib.h>

struct Node1{
    int data;
    struct Node1 * next; 
};


struct Node1 * insertElement(struct Node1 *head,int data){
    struct Node1 * p = (struct Node1 *)malloc(sizeof(struct Node1));
    p->next = head;
    p->data = data;
    return p;

}

struct Node1 * deleteElement(struct Node1* head,int idx){

    struct Node1 *ptr1 = head;
    struct Node1 * ptr2 = head->next;

    for(int i =0;i<idx-1;i++){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = ptr2->next;
    free(ptr2);
    
    return head;

}

struct Node1 * sortList(struct Node1 * head){

}


void display(struct Node1 * p){
    while(p != NULL){
        printf("%d \n",p->data);
        p = p->next;
    }
}


//  typedef struct Node1  A;
int main(){
    // A *p;
    // p = (A *)calloc(sizeof(A));
    struct Node1 *head;
    struct Node1 *first;
    struct Node1 *second;
    struct Node1 *third;
    
    head = (struct Node1 *)malloc(sizeof(struct Node1));
    first = (struct Node1 *)malloc(sizeof(struct Node1));
    second = (struct Node1 *)malloc(sizeof(struct Node1));
    third = (struct Node1 *)malloc(sizeof(struct Node1));


    head->data = 10;
    head->next = first;

    first->data= 17;
    first->next = second;

    second->data = 20;
    second->next= third;

    third->data = 23;
    third->next = NULL;


   
    head = insertElement(head,3);
     printf("LInked list after Insertion:\n");
    display(head);

    printf("\n");

    head= deleteElement(head,2);
      printf("LInked list after Deletion:\n");
    display(head);


    return 0;
}

//declaration of a singly ll