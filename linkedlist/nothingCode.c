#include <stdio.h>
#include <stdlib.h>

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
        printf("Invalid Position.");
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
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    Node *ptr = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        ptr->next = newNode;
        newNode->prev = ptr;
        return;
    }
    newNode->next = ptr->next;
     ptr->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = ptr;
   
}

void delete(Node **head, int pos)
{
    if (pos < 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if (*head == NULL)
    {
        printf("Empty list!");
        return;
    }

    if (pos == 0)
    {
        Node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }

    Node *ptr = *head;
    for (int i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    Node *temp = ptr->next;
    if (ptr->next->next = NULL)
    {
        ptr->next = NULL;
        free(temp);
        return;
    }
    ptr->next = ptr->next->next;
    ptr->next->prev = ptr;
    free(temp);
}

void traverse(Node *head)
{
    Node *p = head;
    printf(" NULL ->");
    while (p != NULL)
    {
        printf(" %d ->", p->data);
        p = p->next;
    }
    printf(" NULL");
}

int getSize(Node *head)
{
    Node *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

void sort(Node *head)
{
    Node *current = head;
    int nodes = getSize(head);

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
}

int get_response()
{
    printf("1. Create Linked List with an initial value.\n");
    printf("2. Insert node at a particular position\n");
    printf("3. Delete node at a particular position.\n");
    printf("4. Display list.\n");
    printf("5. Sort list.\n");
    printf("0. Quit.\n");
    int response;
    printf("Response: ");
    scanf("%d", &response);
    getchar();
    return response;
}

int main()
{
     Node *head = NULL;
    int val, pos;
    while (1)
    {
        switch (get_response())
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
            printf("List = {");
            traverse(head);
            printf("}\n");
            break;
        case 5:
            sort(head);
            printf("List sorted.\n");
            break;
        default:
            printf("Wrong response.");
        }
    }

    return 0;
}