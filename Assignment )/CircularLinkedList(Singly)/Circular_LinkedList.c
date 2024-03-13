#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList();
void displayList(struct Node* head);
struct Node* insertNode(struct Node* head, int data);
struct Node* deleteNodeByData(struct Node* head, int data);
struct Node* deleteNodeByPosition(struct Node* head, int position);
struct Node* sortList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\n1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert Node\n");
        printf("4. Delete Node by Data\n");
        printf("5. Delete Node by Position\n");
        printf("6. Sort List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = createList();
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertNode(head, data);
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                head = deleteNodeByData(head, data);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteNodeByPosition(head, position);
                break;
            case 6:
                head = sortList(head);
                printf("List sorted successfully.\n");
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
struct Node *createList()
{
    struct Node *head = NULL;
    struct Node *newNode, *temp;
    int num, data;

    printf("Enter the number of integers for the linked list: ");
    scanf("%d", &num);

    if (num <= 0)
    {
        printf("Invalid input. Number of integers must be greater than 0.\n");
        return head;
    }

    printf("Enter data for the linked list: ");
    for (int i = 0; i < num; ++i)
    {
        scanf("%d", &data);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    printf("Linked list created successfully.\n");
    return head;
}

void displayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head;

    printf("Circular Singly Linked List: ");
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

struct Node *insertNode(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    printf("Node with data %d inserted successfully.\n", data);
    return head;
}

struct Node* deleteNodeByData(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return head;
    }

    struct Node *current = head, *prev = NULL;

    if (current->data == data) {
        if (current->next == head) {
            free(current);
            head = NULL;
        } else {
            while (current->next != head)
                current = current->next;
            current->next = head->next;
            free(head);
            head = current->next;
        }
        printf("Node with data %d deleted successfully.\n", data);
        return head;
    }

    while (current->next != head && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current->data == data) {
        prev->next = current->next;
        free(current);
        printf("Node with data %d deleted successfully.\n", data);
    } else {
        printf("Node with data %d not found in the list.\n", data);
    }

    return head;
}

struct Node* deleteNodeByPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return head;
    }

    struct Node *current = head, *temp = NULL;
    int count = 1;

    if (position == 1) {
        while (current->next != head)
            current = current->next;

        if (current == head) {
            free(current);
            head = NULL;
        } else {
            current->next = head->next;
            free(head);
            head = current->next;
        }
        printf("Node at position %d deleted successfully.\n", position);
        return head;
    }

  
    while (count < position && current->next != head) {
        temp = current;
        current = current->next;
        count++;
    }

    if (count == position) {
        temp->next = current->next;
        free(current);
        printf("Node at position %d deleted successfully.\n", position);
    } else {
        printf("Node at position %d not found in the list.\n", position);
    }

    return head;
}


struct Node *sortList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty. Sorting not possible.\n");
        return head;
    }

    struct Node *current = head, *index = NULL;
    int temp;

    do
    {
        index = current->next;
        while (index != head)
        {
            if (current->data > index->data)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    } while (current != head);

    return head;
}