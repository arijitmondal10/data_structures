#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int data){
   
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;   
}

struct Node * inOrderPredecessor(struct Node * root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

void inOrder(struct Node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d",root->data);
        inOrder(root->right);
    }
}

struct Node * deleteNode(struct Node* root,int data){
    struct Node * ipre;
    if(root ==NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(data< root->data){
        root->left =  deleteNode(root->left,data);
    }
    else if(data> root->data){
        root->right = deleteNode(root->right,data);
    }
    else{
        ipre = inOrderPredecessor(root);
        root->data = ipre->data;
        root->left = deleteNode(root->left,ipre->data);
    }
    return root;
}

int main(){

    struct Node *p1 = createNode(5);
    struct Node *p2 = createNode(3);
    struct Node *p3 = createNode(6);
    struct Node *p4 = createNode(2);
    struct Node *p5 = createNode(4);
    // struct Node *p6 = createNode(7);

    // linking
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    // p3->right = p6;

    inOrder(p1);

    printf("\n");
    deleteNode(p1,5);
    printf("%d \n",p1->data);
    inOrder(p1);
}