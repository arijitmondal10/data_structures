#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
} Queue;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Queue *create_queue() {
    Queue *new_queue = (Queue *)malloc(sizeof(Queue));
    if (new_queue == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    new_queue->front = new_queue->rear = NULL;
    return new_queue;
}

int is_empty(Queue *q) {
    return (q->front == NULL);
}

void enqueue(Queue *q, int data) {
    Node *new_node = create_node(data);
    if (is_empty(q)) {
        q->front = q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty! Element can't be deleted.\n");
        return -1;
    }

    Node *temp = q->front;
    int data = temp->data;

    q->front = temp->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return data;
}

void display(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    Node *current = q->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue *q = create_queue();
    int choice, data;

    do {
        printf("Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                break;
            case 2: {
                int dequeued = dequeue(q);
                if (dequeued != -1) {
                    printf("Dequeued Element: %d\n", dequeued);
                }
                break;
            }
            case 3:
                display(q);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}

