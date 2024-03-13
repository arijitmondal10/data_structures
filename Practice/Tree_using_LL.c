#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
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
    struct Node *p6 = createNode(7);

    // linking
    p1->left = p2;
    p1->right = p3;
    p2->left = p4;
    p2->right = p5;
    p3->right = p6;

    printf("PreOder Traversal: ");
    preOrder(p1);
    printf("\n");

    printf("InOrder Traversal: ");
    inOrder(p1);
    printf("\n");

    printf("PostOrder Traversal: ");
    postOrder(p1);
    printf("\n");

    /*
    struct Node* p = (struct Node *)malloc(sizeof(struct Node));
    p->data = 2;
    p->left = NULL;
    p->right = NULL;

     struct Node* p1 = (struct Node *)malloc(sizeof(struct Node));
    p1->data = 3;
    p1->left = NULL;
    p1->right = NULL;

     struct Node* p2 = (struct Node *)malloc(sizeof(struct Node));
    p2->data = 4;
    p2->left = NULL;
    p2->right = NULL;

    p->left = p1;
    p->right = p2;

    */
}