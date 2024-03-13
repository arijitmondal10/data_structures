#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 50

typedef struct Queue {
    int queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue create_queue() {
    Queue q;
    q.front = -1;
    q.rear = -1;
    return q;
}

int isEmpty(Queue *q) {
    return (q->front == -1);
}

int isFull(Queue *q) {
    return (q->rear == MAX_QUEUE_SIZE - 1);
}

void enqueue(Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue full!");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->queue[q->rear] = data;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int dequeued_item = q->queue[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return dequeued_item;
}

void display(Queue q) {
    if (isEmpty(&q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.queue[i]);
    }
    printf("\n");
}

int main() {
    Queue q = create_queue();
    enqueue(&q, 15);
    enqueue(&q, 8);
    enqueue(&q, 4);
    enqueue(&q, 9);
    enqueue(&q, 13);
    enqueue(&q, 19);
    display(q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    display(q);

    enqueue(&q, 24);
    display(q);

    return 0;
}

