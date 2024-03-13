#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data >= root->data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(Node *root)
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
    int n;
    printf("Enter the total size of the bst:");
    scanf("%d", &n);
    int input[n];
    printf("Enter the %d no of elements for the Bst:", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, input[i]);
    }
    printf("Inoder Traversal:");
    inOrder(root);
    printf("\n");

    printf("Preoder Traversal:");
    preOrder(root);
    printf("\n");

    printf("Postoder Traversal:");
    postOrder(root);
    printf("\n");
}