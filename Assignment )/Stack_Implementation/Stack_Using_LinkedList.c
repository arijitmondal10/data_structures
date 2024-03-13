#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
    int size;
} Stack;

int isEmpty(Stack *stk) {
    return (stk->top == NULL);
}

Node *createNode(int data) {
    Node *newNode = (Node *)calloc(1, sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Stack *stk, int data) {
    Node *newNode = createNode(data);
    newNode->next = stk->top;
    stk->top = newNode;
    stk->size++;
}

void pop(Stack *stk) {
    if (isEmpty(stk)) {
        printf("Stack Underflow!\n");
        return;
    }
    Node *temp = stk->top;
    stk->top = stk->top->next;
    free(temp);
    stk->size--;
}

void display(Stack *stk) {
    printf("stack:\n");
    if (isEmpty(stk)) {
        printf("Stack is empty.\n");
        return;
    }
    Node *temp = stk->top;
    while (temp != NULL) {
        printf("\t%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Stack *createStack() {
    Stack *stack = (Stack *)calloc(1, sizeof(Stack));
    stack->size = 0;
    stack->top = NULL;
    return stack;
}

int main() {
    Stack *stk = createStack();

    push(stk, 3);
    push(stk, 9);
    push(stk, 1);
    push(stk, 6);
    push(stk, 17);

    display(stk);

    pop(stk);
    pop(stk);

    display(stk);

    push(stk, 45);

    display(stk);
    return 0;
}

