#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int precedance(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/' || op == '%')
    {
        return 2;
    }
    else if (op == '^')
    {
        return 4;
    }
    else
    {
        return 0;
    }
}

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

char stackTop(struct Stack *ptr)
{
    return ptr->arr[ptr->top];
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '(' || ch == ')')
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
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct Stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow !!! Cannot push %d in the stack", value);
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = value;
}

char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow !!!No elements are there... ");
        return -1;
    }
    char temp = ptr->arr[ptr->top];
    ptr->top--;
    return temp;
}

char *infixToPostfix(char *infix)
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postFix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postFix[j] = infix[i];
            j++;
            i++;
        }
        else if (infix[i] == '(')
        {
            push(sp, infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(sp) && stackTop(sp) != '(')
            {
                postFix[j] = pop(sp);
                j++;
            }
            if (!isEmpty(sp) && stackTop(sp) == '(')
            {
                pop(sp);
            }
            i++;
        }
        else
        {

            if (precedance(infix[i]) > precedance(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postFix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postFix[j] = pop(sp);
        j++;
    }
    postFix[j] = '\0';
    return postFix;
}

int evaluatePostfix(char *postfix)
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    int i = 0;

    while (postfix[i] != '\0')
    {
        if (!isOperator(postfix[i]))
        {
            push(sp, postfix[i] - '0');
        }
        else
        {
            int operand2 = pop(sp);
            int operand1 = pop(sp);
            switch (postfix[i])
            {
            case '+':
                push(sp, operand1 + operand2);
                break;
            case '-':
                push(sp, operand1 - operand2);
                break;
            case '*':
                push(sp, operand1 * operand2);
                break;
            case '/':
                push(sp, operand1 / operand2);
                break;
            case '%':
                push(sp, operand1 % operand2);
                break;
            case '^':
                push(sp, pow(operand1, operand2));
                break;
            }
        }
        i++;
    }

    return pop(sp); 
}

int main()
{
    char infix[100];
    printf("Enter the Expression:");
    fgets(infix,sizeof(infix),stdin);
    infix[strcspn(infix, "\n")] = '\0';
    printf("The Postfix result is:%s \n", infixToPostfix(infix));

    char * postfix = infixToPostfix(infix);

    printf("The Evaluation Result is: %d",evaluatePostfix(postfix));

    return 0;
}
