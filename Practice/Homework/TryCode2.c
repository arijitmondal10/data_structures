#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}node;

node * createNode(int data){
    node * ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
}

void insert(node ** head,int idx,int data){
    node * newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        newNode->next = *head;
        return;
    }
    node *ptr = *head;
    if(idx = 0){
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        newNode->next = *head;
        *head = newNode;
        ptr->next = *head;
        return;
    }
    for(int i =0;i< idx-1;i++){
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;

}

void delete(){
    
}
void traverse(node * head){
    node * ptr = head;
    do{
        printf("%d ->",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("NULL");
}
int main(){
    node * head = NULL;
    // insert(&head,0,10);
    // traverse(head);
    int pos,data;
     int response;
    do{
        printf("1.Insert Node.\n");
        printf("2.traverse list.\n");
        printf("3.delete node.\n");
         printf("4.create list\n");
        printf("0.Exit\n");
        printf("Enter Your choice :");
        scanf("%d",&response);

        switch(response){
            case 1:
            printf("Enter position and data :");
            scanf("%d%d",&pos,&data);
            insert(&head,pos,data);
            break;

            case 2:
            printf("List:{ ");
            traverse(head);
            printf(" }\n");
            break;

            case 3:
            printf("Enter position :");
            scanf("%d",&pos);
            delete(&head,pos);
            break;

            case 4:
            createList(head);
            break;
            
            case 0:
            break;

            default:
            printf("wrong Input...");

    }
}while(response!=0);
}