#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    struct Stack *next;
};

// if we make top as a global variable then we can use the pop function without double pointer.
// but we have to change the name top(argument)
//-->

int isFull(struct Stack *top)
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    if (s == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Stack *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Stack *push(struct Stack *top, int data)
{

    if (isFull(top))
    {
        printf("Stack Overflow...");
    }
    else
    {
        struct Stack *ptr = (struct Stack *)malloc(sizeof(struct Stack));
        ptr->data = data;
        ptr->next = top;
        top = ptr;
    }
    return top;
}

int peek(struct Stack *top, int position)
{
    struct Stack *ptr = top;
    for (int i = 0; (i < position - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int pop(struct Stack **top)
{
    if (isEmpty(*top))
    {
        printf("Stack Underflow");
    }
    else
    {
        struct Stack *ptr = *top;
        *top = (*top)->next;
        int val = (*top)->data;
        free(ptr);
        return val;
    }
}

int stacktop(struct Stack *top)
{
    return top->data;
}

int stackBottom(struct Stack *top)
{
    struct Stack *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

void traverse(struct Stack *ptr)
{

    while (ptr != NULL)
    {
        printf("%d \n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    struct Stack *top = NULL; //-->
    top = push(top, 10);
    top = push(top, 11);
    top = push(top, 12);
    // push(top,12);  you need to use double pointer to dereference the dp to get the original pointer.
    // int element = pop(&top);
    // printf("Poped element is: %d\n", element);
    // int temp = peek(top, 2);
    // printf("%d", stackBottom(top));

    traverse(top);
}