#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * deleteAtFirst(struct Node * head){
    struct Node * p = head;
    struct Node * ptr = head->next;
    while(ptr->next != head){
        ptr = ptr->next;
    }
    ptr->next = head->next;
    head = head->next;
    free(p);
    return head;

}

struct Node * deleteAtIndex(struct Node * head,int idx)
{
     struct Node * p = head;
     struct Node * q = p ->next;
     for(int i =0;i< idx-1;i++){
        p = p->next;
        q = q->next;
     }
     
    p->next = q->next;
    free(q);
    return head;

}

struct Node * deleteAtEnd(struct Node * head){
    struct Node * p = head;
    struct Node * q = p->next;
    while(q->next != head){
        p = p->next;
        q = q->next;
    }
    p->next = head;
    free(q);
    return head;
    
}
void Traverse(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

int main(){
     struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *frth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    frth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = frth;

    frth->data = 4;
    frth->next = head;

    head = deleteAtEnd(head);
    Traverse(head);
}