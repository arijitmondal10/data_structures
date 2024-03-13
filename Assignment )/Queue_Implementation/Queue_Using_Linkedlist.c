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
    Node *new_node = (Node *)calloc(1, sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Queue *create_queue() {
    Queue *new_queue = (Queue *)malloc(sizeof(Queue));
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
        return;
    }
    q->rear->next = new_node;
    q->rear = new_node;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty! ");
        return -1;
    }

    Node *temp = q->front;
    int data = q->front->data;

    if (q->front == q->rear) {
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    free(temp);
    return data;
}

void display(Queue *q) {
    Node *current = q->front;
    printf("[  ");
    while (current != NULL) {
        printf("%d  ", current->data);
        current = current->next;
    }
    printf("]\n");
}

int main() {
    Queue *q = create_queue();
    enqueue(q, 15);
    enqueue(q, 8);
    enqueue(q, 4);
    enqueue(q, 9);
    enqueue(q, 13);
    enqueue(q, 19);
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    enqueue(q, 24);
    display(q);

    return 0;
}

