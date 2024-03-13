//first DLLNode is p and 2nd is q by default head is there

// create the third node r


#include<stdio.h>
#include<stdlib.h>

struct DLLNode{
    int data;
    struct DLLNode * next;
    struct DLLNode * prev;
};

struct DLLNode * InsertAtBig(struct DLLNode * head,int data){
    struct DLLNode * ptr = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    ptr->data = data;
    ptr->next = head;
    head->prev = ptr;
    ptr->prev = NULL;

    head = ptr;
    return head;
}

struct DLLNode * insertAtMid(struct DLLNode * head, int idx,int data){
    struct DLLNode * ptr = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    ptr->data = data;
    struct DLLNode * p = head;
    for(int i=0;i<idx-1;i++){
        p = p->next;
    }
    ptr->next = p->next;
    p->next->prev = ptr;
    p->next = ptr;
    ptr->prev =p;

    return head;
}
  
struct DLLNode * insertAtEnd(struct DLLNode * head, int data){
    struct DLLNode * ptr = (struct DLLNode *)malloc(sizeof(struct DLLNode));
    struct DLLNode * p = head;
    while(p->next != NULL){
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;

    return head;

}  
void traverse(struct DLLNode * ptr){
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
       struct  DLLNode*head;
    struct DLLNode*second;
    struct DLLNode*third;

    head = (struct  DLLNode*)malloc(sizeof(struct  DLLNode));
    second = (struct  DLLNode*)malloc(sizeof(struct  DLLNode));
    third = (struct  DLLNode*)malloc(sizeof(struct  DLLNode));
   
   head->data = 1;
   head->prev = NULL;
   head->next = second;
  
   second->data = 2;
   second->prev = head;
   second->next = third;

   third->data = 3;
   third->prev = second;
   third->next = NULL;

   head = insertAtEnd(head,5);
   head = insertAtEnd(head,7);
   traverse(head);
}