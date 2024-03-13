#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function prototypes
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

// Function to create a circular doubly linked list
struct Node* createList() {
    struct Node* head = NULL;
    struct Node* newNode, *temp;
    int num, data;

    printf("Enter the number of integers for the linked list: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Invalid input. Number of integers must be greater than 0.\n");
        return head;
    }

    printf("Enter data for the linked list: ");
    for (int i = 0; i < num; ++i) {
        scanf("%d", &data);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            newNode->prev = head;
        } else {
            temp = head->prev;
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    printf("Linked list created successfully.\n");
    return head;
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;

    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

// Function to insert a node into the circular doubly linked list
struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        struct Node* temp = head->prev;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
    }

    printf("Node with data %d inserted successfully.\n", data);
    return head;
}

// Function to delete a node from the circular doubly linked list by data
struct Node* deleteNodeByData(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return head;
    }

    struct Node *current = head;

    // Traverse the list to find the node with the specified data
    while (current->data != data && current->next != head) {
        current = current->next;
    }

    if (current->data == data) {
        if (current->next == head && current->prev == head) {
            free(current);
            head = NULL;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (current == head) {
                head = head->next;
            }
            free(current);
        }
        printf("Node with data %d deleted successfully.\n", data);
    } else {
        printf("Node with data %d not found in the list.\n", data);
    }

    return head;
}

// Function to delete a node from the circular doubly linked list by position
struct Node* deleteNodeByPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return head;
    }

    struct Node *current = head;
    int count = 1;

    // Traverse the list to find the node at the specified position
    while (count < position && current->next != head) {
        current = current->next;
        count++;
    }

    if (count == position) {
        if (current->next == head && current->prev == head) {
            free(current);
            head = NULL;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (current == head) {
                head = head->next;
            }
            free(current);
        }
        printf("Node at position %d deleted successfully.\n", position);
    } else {
        printf("Node at position %d not found in the list.\n", position);
    }

    return head;
}

// Function to sort the circular doubly linked list
struct Node* sortList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Sorting not possible.\n");
        return head;
    }

    struct Node *current = head, *index = NULL;
    int temp;

    do {
        index = current->next;
        while (index != head) {
            if (current->data > index->data) {
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