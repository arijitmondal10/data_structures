#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// struct Node1{
//     struct Node * left ;

//     struct Node * right;
// };

struct Node * createNode(int data){
    struct Node* ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;   
}


void insert(struct Node *root, int data)
{
    struct Node * prev = NULL;
    while(root != NULL){
        prev = root;
        if(data == root->data){
            return;
        }
        else if(data > root->data){
            root = root->right;
        }
        else{
            root = root->left;
        }
    } 
    struct Node * new = createNode(data);
    if(prev->data < data){
        prev->right = new;
    }
    else{
        prev->left = new;
    }
}   

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{
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

    insert(p1,11);

    // printf("%d",p1->right->right->data);
    inOrder(p1);
}