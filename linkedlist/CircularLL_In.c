#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtBig(struct Node *head, int data)
{

    struct Node *p = head->next;

    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = data;

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = q;
    q->next = head;

    head = q;
    return head;
}

struct Node * insertAtMid(struct Node * head, int idx,int data){
    struct Node * ptr = head;
    
     struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    for(int i =0;i<idx-1;i++){
        ptr = ptr->next;
    }
    q->data = data;
    q->next = ptr->next;
    ptr->next = q;

    return head;
}

struct Node* insertAtEnd(struct Node *head,int data){
    struct Node *ptr = head;
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    q->data = data;
    
    do{
        ptr = ptr->next;
    } while (ptr->next != head);
    ptr->next= q;
    q->next = head;
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
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 17;
    third->next = head;

    head = insertAtEnd(head,3);
    Traverse(head);
}