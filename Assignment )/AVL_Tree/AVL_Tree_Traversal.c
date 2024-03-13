#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode
{
    int data;
    struct AVLNode *left, *right;
    int height;
}AVLNode;

int getHeight(AVLNode *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

AVLNode *createNode(int data)
{
    AVLNode *newNode = (AVLNode *)calloc(1,sizeof(AVLNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int getBalanceFactor(AVLNode *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

AVLNode *rightRotate(AVLNode *y)
{
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return x;
}

AVLNode *leftRotate(AVLNode *x)
{
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

AVLNode *insert(AVLNode *node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    if (bf > 1 && data < node->left->data)
    {
        return rightRotate(node);
    }
    if (bf < -1 && data > node->right->data)
    {
        return leftRotate(node);
    }
    if (bf > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bf < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void InOrder(AVLNode *root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}

void preOrder(AVLNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(AVLNode *root)
{
    if(root!=NULL)
    {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
    }
}
int main()
{
    AVLNode *root = NULL;
    int n,data;
    printf("How many node you want to take in AVL tree : ");
    scanf("%d",&n);
    printf("Enter the nodes : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }

    printf("PreOrder Traversal : ");
    preOrder(root);

    printf("\nInOrder Traversal : ");
    InOrder(root);

    printf("\nPostOrder Traversal : ");
    postOrder(root);
    return 0;
}


