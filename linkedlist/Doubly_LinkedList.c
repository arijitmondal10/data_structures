#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

void insert(Node **head, int pos, int data)
{
    if (pos < 0)
    {
        printf("Position Doesnot Exist.\n");
        return;
    }

    Node *new_node = createNode(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    if (pos == 0)
    {
        new_node->next = *head;
        (*head)->prev = new_node;
        *head = new_node;
        return;
    }

    Node *current = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        current->next = new_node;
        new_node->prev = current;
        return;
    }
    new_node->next = current->next;
    current->next = new_node;
    new_node->next->prev = new_node;
    new_node->prev = current;
}

void delete(Node **head, int pos) {
    if (pos < 0) {
        printf("Position Doesnot Exist.\n");
        return;
    }

    if (*head == NULL) {
        printf("The list is Empty!");
        return;
    }

    if ((*head)->next == NULL) {
        Node *temp = *head;
        free(temp);
        *head = NULL;
        return;
    }

    if (pos == 0) {
        Node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }

    Node *current = *head;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }

    Node *temp = current->next;
    if (current->next->next == NULL) {
        current->next = NULL;
        free(temp);
        return;
    }
    current->next = current->next->next;
    current->next->prev = current;
    free(temp);
}

void traverse(Node *head)
{
    Node *current = head;
    printf("NULL<->");
    while (current != NULL)
    {
        printf("%d <->", current->data);
        current = current->next;
    }
    printf("NULL");
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
    int size = get_size(head);

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
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
    printf("The list has been sorted successfully.\n");
    printf("Now traverse The list. \n");
}

int user_Choice()
{
    printf("1. Create Doubly Linked List with an initial value.\n");
    printf("2. Insert node at a given position\n");
    printf("3. Delete node at a given position.\n");
    printf("4. Display the list.\n");
    printf("5. Sort the list.\n");
    printf("0. Exit.\n");
    int choice;
    printf("Enter: ");
    scanf("%d", &choice);
    getchar();
    return choice;
}


// Here the starting position is 0 (Head index) //
int main()
{
    Node *head = NULL;
    int val, pos;
    while (true)
    {
        switch (user_Choice())
        {
        case 0:
            return 0;
        case 1:
            printf("Initialize list with a value: ");
            scanf("%d", &val);
            head = createNode(val);
            break;
        case 2:
            printf("Enter value and position: ");
            scanf("%d%d", &val, &pos);
            insert(&head, pos, val);
            break;
        case 3:
            printf("Enter position: ");
            scanf("%d", &pos);
            delete (&head, pos);
            break;
        case 4:
            printf("List = ");
            traverse(head);
            printf("\n");
            break;
        case 5:
            sort(head);
            break;
        default:
            printf("Wrong input.");
        }
    }
    return 0;
}
