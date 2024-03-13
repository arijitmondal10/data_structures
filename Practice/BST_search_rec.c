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

struct Node *searchBST(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data < key)
    {
        return searchBST(root->right, key);
    }
    else
    {
        return searchBST(root->left, key);
    }
}

struct Node *searchBSTiterative(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
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

    struct Node *p = searchBSTiterative(p1, 4);
    if (p != NULL)
    {
        printf("Found : %d", p->data);
    }
    else
    {
        printf("Element not found");
    }
}