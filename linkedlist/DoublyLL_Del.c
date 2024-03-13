#include<stdio.h>
#include<stdlib.h>

struct DLLNode{
    int data;
    struct DLLNode * next;
    struct DLLNode * prev;
};

struct DLLNode * DeleteAtFirst(struct DLLNode * head){
    struct DLLNode * ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}

struct DLLNode * DeleteAtMid(struct DLLNode * head,int idx){
    struct DLLNode * p = head;
    struct DLLNode * q = p->next;
    for(int i =0;i<idx-1;i++){
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    q->next->prev = p;
    free(q);

    return head;

}

struct DLLNode * DeleteAtEnd(struct DLLNode * head){
    struct DLLNode * p = head;
    struct DLLNode * ptr = p->next;
    while(ptr->next != NULL){
        p= p->next;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);   
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
    struct DLLNode*fourth;

    head = (struct  DLLNode*)malloc(sizeof(struct  DLLNode));
    second = (struct  DLLNode*)malloc(sizeof(struct  DLLNode));
    third = (struct  DLLNode*)malloc(sizeof(struct  DLLNode));
    fourth =(struct  DLLNode*)malloc(sizeof(struct  DLLNode));

   head->data = 1;
   head->prev = NULL;
   head->next = second;
  
   second->data = 2;
   second->prev = head;
   second->next = third;

   third->data = 3;
   third->prev = second;
   third->next = fourth;

   fourth->data = 4;
   fourth->prev = third;
   fourth->next = NULL;

   head = DeleteAtEnd(head);
   traverse(head);

}