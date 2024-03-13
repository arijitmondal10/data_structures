#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * next;
};

struct node * deleteAtFirst(struct node * head){
       struct node * ptr = head;
       head= head->next;
       free(ptr);
       return head;
}

struct node * deleteAtIndex(struct node * head,int idx){
    struct node* p = head;
    struct  node * q = p->next;
    for(int i=0;i<idx-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next= q->next;
    free(q);
    return head;
      
    
}

struct node * deleteAtLast(struct node * head){
    struct node* p = head;
    struct  node * q = p->next;
    
    while(q->next != NULL){
        p = p->next;
        q = q->next;
    }
    p->next= NULL;
    free(q);
    return head;
}

struct node * deleteAtValue(struct node * head,int value){
    struct node * p = head;
    struct node * q = head->next;

    while(q->data != value && q->next != NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data==value){
        p->next= q->next;
    }
    free(q);
    return head;
}
void traverse(struct node* ptr){

    while(ptr != NULL){
    printf("%d \n",ptr->data);
    ptr = ptr->next;
}
}


int main(){

    struct node * head;
    struct node * first;
    struct node * second;
    struct node * third;

    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 100;
    head->next = first;

    first->data = 110;
    first->next= second;

    second->data = 91;
    second->next = third;

    third->data = 95;
    third->next = NULL;

    // head = deleteAtFirst(head);
    head= deleteAtIndex(head,2);
    // head = deleteAtValue(head,91);
    traverse(head);



}