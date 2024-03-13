#include <stdio.h>
#include <stdlib.h>
#define MAX_Stack_SIZE 100

typedef struct Stack
{
    int size;
    int top;
    int *arr;
}Stack;

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == MAX_Stack_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int StackTop(struct Stack *ptr)
{
    return ptr->arr[ptr->top];
}

int StackBottom(struct Stack *ptr)
{
    return ptr->arr[0];
}

void push(struct Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow !!! Cannot push %d in the Stack", value);
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = value;
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow !!!No elements are there... ");
        return -1;
    }
    int temp = ptr->arr[ptr->top];
    ptr->top--;
    return temp;
}

void display(Stack * stk) {
    printf("Stack:\n");
    for (int i = stk->top; i >= 0; i--) {
        printf("%d\n",stk->arr[i]);
    }
    printf("\n");
}

int main()
{
    Stack*stk = (Stack *)malloc(sizeof(Stack));
    stk->size = 6;
    stk->top = -1;
    stk->arr = (int *)malloc(stk->size * sizeof(int));

    push(stk, 15);
    push(stk, 9);
    push(stk, 10);
    push(stk, 8);
    push(stk, 17);

    display(stk);

    pop(stk);
    pop(stk);

    display(stk);

    push(stk, 45);
    return 0;
}