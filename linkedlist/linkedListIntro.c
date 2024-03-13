#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node * next;
    
};

void traverse(struct Node* ptr){

    while(ptr != NULL){
    printf("%d \n",ptr->data);
    ptr = ptr->next;
}
}

struct Node * createNode(int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

// void sorting(struct Node* head){
   
//     struct Node * p = head;
//     while(p!= NULL){
        
//           struct Node * q = p->next;
//        while(q!= NULL){
//         if(p->data > q->data ){
//             p->next = q->next;
//             q->next = p; 
//         }
//         q = q->next;
//     }
//     p = p->next;
// }
// }
 
struct Node * swap(struct Node* head,int index){
    struct Node* p = head;
    struct Node * q = p->next;
    struct Node * r = q->next;
    int i =1;
    while(i!= index-1){
        p = p->next;
        q = q->next;
        r = r->next;
        i++;
    }
    q->next = r->next;
    p->next = r;
    r->next = q;

    return head;
}

int main(){

    struct  Node*head;
    struct Node*second;
    struct Node*third;
    struct Node*fourth;
    struct Node * fifth = createNode(10); // this type should be used...

    //allocates memory for the nodes of the list in heap

    head = (struct  Node*)malloc(sizeof(struct  Node));
    second = (struct  Node*)malloc(sizeof(struct  Node));
    third = (struct  Node*)malloc(sizeof(struct  Node));
    fourth = (struct  Node*)malloc(sizeof(struct  Node));
   
    // links first and second node
   head->data = 7;
   head->next = second;

    // links second and third node
   second->data = 30;
   second->next = third;

    // terminates the list at the third node
   third->data = 17;
   third->next = fourth;

   fourth->data = 50;
   fourth->next = fifth;

   




    swap(head,2);
   traverse(head);

    return 0;
}
