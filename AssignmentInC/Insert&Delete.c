#include<stdio.h>
#include<stdlib.h>

struct Node1{
    int data;
    struct Node1 * next; 
};


struct Node1 * insertElement(struct Node1 * head,int data){
    struct Node1 * p = (struct Node1 *)malloc(sizeof(struct Node1));
    p->next = head;
    p->data = data;
    return p;

}

void display(struct Node1 * p){
    while(p->next != NULL){
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

    // head = insertElement(head,3);
    display(head);


    return 0;
}