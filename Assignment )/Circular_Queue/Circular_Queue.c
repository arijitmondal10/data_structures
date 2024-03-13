#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

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

int is_empty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

int is_full(Queue *q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue *q, int data) {
    if (is_full(q)) {
        printf("Queue full! Element can't be inserted");
    } else {
        if (is_empty(q)) {
            q->front = 0;
            q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        }
        q->queue[q->rear] = data;
    }
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty! Element can't be deleted.");
        return -1;
    }

    int data = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return data;
}

void display(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!");
        return;
    }
    int i = q->front;
    printf("Queue: ");
    while (i != q->rear) {
        printf("%d ", q->queue[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d\n", q->queue[q->rear]);
}

int main() {
    Queue q = create_queue();
    enqueue(&q, 15);
    enqueue(&q, 8);
    enqueue(&q, 4);
    enqueue(&q, 9);
    enqueue(&q, 13);
    enqueue(&q, 19);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    enqueue(&q, 24);
    display(&q);

    return 0;
}
