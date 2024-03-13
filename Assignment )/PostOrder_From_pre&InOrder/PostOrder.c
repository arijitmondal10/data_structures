#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int x, int n) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void display_PostOrder(int inorder[], int preOrder[], int n) {
    int rootIndex = search(inorder, preOrder[0], n);

    if (rootIndex != 0)
        display_PostOrder(inorder, preOrder + 1, rootIndex);

    if (rootIndex != n - 1)
        display_PostOrder(inorder + rootIndex + 1, preOrder + rootIndex + 1, n - rootIndex - 1);

    printf("%d ", preOrder[0]);
}

int main() {
    int n;
    printf("Enter the total number of nodes in the tree: ");
    scanf("%d", &n);

    int inOrder[n], preOrder[n];

    printf("Enter inorder traversal of the tree:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &inOrder[i]);

    printf("Enter preorder traversal of the tree:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &preOrder[i]);

    printf("Postorder traversal of the tree is: ");
    display_PostOrder(inOrder, preOrder, n);
}