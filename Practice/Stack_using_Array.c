#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
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

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int stackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow !!! Cannot push %d in the stack", value);
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = value;
}

int pop(struct stack *ptr)
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

int peek(struct stack *ptr, int i)
{
    int temp = ptr->top - i - 1;
    if (temp > 0)
    {
        printf("Error!!!");
    }
    else
    {
        return ptr->arr[temp];
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 10);
    push(s, 11);
    push(s, 12);
    push(s, 13);
    push(s, 14);
    push(s, 15);

    // s->arr[0] = 4;
    // s->top++;

    // s->arr[1] = 5;
    // s->top++;

    // s->arr[2] = 6;
    // s->top++;

    // s->arr[3] = 7;
    // s->top++;

    // s->arr[4] = 8;
    // s->top++;

    // printf("The element %d  has been poped from the stack\n",pop(s));
    // printf("The element %d has been poped from the stack \n",pop(s));
    // printf("The element %d has been poped from the stack \n",pop(s));

    // for(int i =1;i<=s->size;i++){
    //     printf("The element at %d th position is: %d \n",i,pop(s));
    // }

    // printf("\n");

    for (int i = s->size; i >= 1; i--)
    {
        printf("The element at %d th position is: %d \n", i, pop(s));
    }
    // printf("The top most element in the stack is %d \n",stackTop(s));

    // printf("The bottom most element in the stack is %d \n",stackBottom(s));

    // push(s,10);
    // printf("%d",pop(s));

    // if(isFull(s)){
    //     printf("The stack is full.");
    // }
    // else{
    //     printf("The stack is  empty.");
    // }
    return 0;
}