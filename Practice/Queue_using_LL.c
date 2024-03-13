#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

//global variable
 struct Node * f = NULL;
 struct Node * r = NULL;

int isFull(struct Node *ptr){
    struct Node *s = (struct Node *)malloc(sizeof(struct Node));
    if (s == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct Node *ptr)
{
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node * enQueue(int data){
    if(isFull(f)){
        printf("Queue is Full already...");
    }
    else{
        struct Node * p = (struct Node*)malloc(sizeof(struct Node));
        p->data = data;
        p->next = NULL;
        if(f==NULL){
            f= r = p;
        }
        else{
            r->next = p;
            r = p;
        } 
    }
}

int deQueue(){
    struct Node * ptr= f;
    int val = -1;
    if(isEmpty(f)){
        printf("No element to delete");
        exit(0);
    }
    else{
        f = f->next;
         val = ptr->data;
        free(ptr);
    }
    return val;
}



void traverse(struct Node *f)
{

    while (f != NULL)
    {
        printf("%d \n", f->data);
        f = f->next;
    }
}

int main(){

    enQueue(10);
    enQueue(11);
   printf("Element:%d", deQueue());
    // if(isEmpty(q)){
    //     printf("Empty");
    // }
    // traverse(f);
}