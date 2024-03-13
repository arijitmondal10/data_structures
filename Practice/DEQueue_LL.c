#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

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
struct Node * enQueueF(struct Node **f,struct Node** r,int data){
    if(isFull(*f)){
        printf(" Queue is full...");
    }
    else{
        struct Node * p = (struct Node *)malloc(sizeof(struct Node));
        p->data = data;
        p->next = NULL;
        if(*f==NULL){
            *f=*r=p;
        }
        else{
        p->next = *f;
        *f= p;
        }
    }
}
  
struct Node * enQueueR(struct Node **f,struct Node **r,int data){
    if(isFull(*f)){
        printf("The Queue is already full");
    }
    else{
        struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->next = NULL;
        if(*f == NULL){
            *f = *r = ptr;
        }
        else{
            (*r)->next = ptr;
            (*r) = ptr;
        }
    }
}
struct Node * deQueueF(struct Node **f,struct Node **r){
    if(isEmpty(*f)){
        printf("Empty.");
    }
    else{
    int a = -1;
    struct Node * ptr = *f;
    *f = (*f)->next;
    a = ptr->data;
    free(ptr);
    }
    return *f;
}
struct Node * deQueueR(struct Node **f,struct Node ** r){
    int a = -1;
    struct Node * ptr = *f;
    if(isEmpty(*f)){
        printf("The Queue is already empty...");
    }
    else{
        while(ptr->next != *r){
            ptr = ptr->next;
        }
       *r = ptr;
        ptr= ptr->next;
        a = ptr->data;
        free(ptr);
        (*r)->next = NULL;
    }
    return *f;
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
    struct Node * f = NULL;
    struct Node * r = NULL;

    enQueueF(&f,&r,10);
    enQueueF(&f,&r,11);
    enQueueF(&f,&r,12);
    enQueueF(&f,&r,13);

    // f= enQueueF(f,r,11);
    // if(isEmpty(f)){
    //     printf("Empty");
    // }

    printf("Before:\n");
    traverse(f);
    // enQueueR(&f,&r,14);
    // deQueueR(&f,&r);
    // deQueueR(&f,&r);
    // deQueueR(&f,&r);
   
    printf("After:\n");
    deQueueF(&f,&r);
    traverse(f);

}