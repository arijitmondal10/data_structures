#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
    struct Node * prev;
}node;

node * createNode(int data){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

void createList(node *head){
    int n;
    int data;
    node * newNode;
    printf("Enter the size of the list:");
    scanf("%d",&n);

    for(int i =0;i<n;i++){
        scanf("%d",&data);
        newNode = createNode(data);

        if(head == NULL){
            head = newNode;
            return;
        }
        else{
        node * ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->prev = ptr;
        }
    }
}

void insert(node ** head,int index,int data){
    node * newNode = createNode(data);
    if(*head==NULL){
        *head = newNode;
        return;
    }
    if(index==0){
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
    node *ptr = *head;
    for(int i=0;i<index-1;i++){
        ptr= ptr->next;
    }
    node* p = ptr->next;
    if(ptr->next ==NULL){
        ptr->next = newNode;
        newNode->prev = ptr;
        return;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = p;
    p->prev = newNode;

}

void delete(node ** head,int pos){
    if(*head==NULL){
        printf("No elements are there to delete...\n");
        return;
    }
    node * ptr = *head;
    if(pos==0 && ptr->next ==NULL){
        free(ptr);
        *head =NULL;
        printf("No elemets are present in the list right now.");
        return;
    }
    if(pos ==0 &&ptr->next != NULL){
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(ptr);
        return;
    }
    for(int i=0;i<pos-1;i++){
        ptr = ptr->next;
    }
    node * p = ptr->next;
    ptr->next = p->next;
    p->prev = ptr;
    free(p);
}

void traverse(node * ptr){
    while(ptr != NULL){
        printf("%d ->",ptr->data);
        ptr= ptr->next;
    }
    printf("NULL");
}

int main(){
    node * head = NULL;
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
