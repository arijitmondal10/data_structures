#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

void traverse(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

void insert(Node **head, int pos, int data)
{
    if (pos < 0)
    {
        printf("Position Doesnot Exist.");
        return;
    }
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    if (pos == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *ptr = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void delete(Node **head, int pos)
{
    if (pos < 0)
    {
        printf(" Position Doesnot Exist.\n");
        return;
    }

    if (*head == NULL)
    {
        printf("The list is Empty!");
        return;
    }

    if (pos == 0)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *current = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

int user_Input()
{
    printf("1. Create Linked List with an initial value.\n");
    printf("2. Insert node at a given position\n");
    printf("3. Delete node at a given position.\n");
    printf("4. Display the list.\n");
    printf("5. Sort the list.\n");
    printf("0. Exit.\n");
    int choice;
    printf("Enter your Choice : ");
    scanf("%d", &choice);
    return choice;
}

int get_size(Node *head)
{
    Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        current = current->next;
        count++;
    }
    return count;
}

void sort(Node *head)
{
    Node *current = head;
    int nodes = get_size(head);

    for (int i = 0; i < nodes - 1; i++)
    {
        for (int j = 0; j < nodes - i - 1; j++)
        {
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }
        current = head;
    }
    printf("The list is sorted successfully...");
    printf("Now traverse the list.");
}

int main()
{

    Node *head = NULL;
    int val, pos;
    while (true)
    {
        switch (user_Input())
        {
        case 0:
            return 0;
        case 1:
            printf("Initialize list with a value: ");
            scanf("%d", &val);
            head = createNode(val);
            break;
        case 2:
            printf("Enter value and position : ");
            scanf("%d%d", &val, &pos);
            insert(&head, pos, val);
            break;
        case 3:
            printf("Enter position : ");
            scanf("%d", &pos);
            delete (&head, pos);
            break;
        case 4:
            printf("List = ");
            traverse(head);
            printf("\n\n");
            break;
        case 5:
            sort(head);
            break;
        default:
            printf("Wrong Input.");
        }
    }

    return 0;
}
