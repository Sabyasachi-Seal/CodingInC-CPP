#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int *arr;
    int top;
} stack;
int limit;
void create(stack *);
void push(stack *n, int);
void display(stack);
int pop(stack *);
int main()
{
    stack a, b, c;
    int decision = 1, choice, n;
    printf("Enter the size of each stack: ");
    scanf("%d", &limit);
    if (limit > 0)
    {
        create(&a);
        create(&b);
        create(&c);
        a.top = b.top = c.top = -1;
        while (decision)
        {
            printf("Input Element: ");
            scanf("%d", &n);
            if (!isfull(a))
            {
                push(&a, n);
            }
            else
            {
                if (!isfull(b))
                {
                    int temp = pop(&a);
                    push(&b, temp);
                    push(&a, n);
                }
                else
                {
                    if (!isfull(c))
                    {
                        int temp1 = pop(&b);
                        push(&c, temp1);
                        temp1 = pop(&a);
                        push(&b, temp1);
                        push(&a, n);
                    }
                    else
                    {
                        printf("!!FuLL!!\n");
                    }
                }
            }
            printf("a: ");
            display(a);
            printf("b: ");
            display(b);
            printf("c: ");
            display(c);
            printf("0-Exit and 1-Continue: ");
            scanf("%d", &decision);
        }
    }
    else
    {
        printf("Enter a positive value");
    }
    return 0;
}
void create(stack *new)
{
    new->arr = (int *)malloc(limit * sizeof(int));
}
void push(stack *new, int num)
{
    if (new->top == limit - 1)
        printf("overflow condition \n");
    else
    {
        new->top++;
        new->arr[new->top] = num;
    }
}
int pop(stack *new)
{
    if (new->top == -1)
        printf("underflow condition\n");
    else
        return new->arr[new->top--];
}
int isfull(stack new)
{
    if (new.top == limit - 1)
        return 1;
    else
        return 0;
}
int top(stack new)
{
    return new.arr[new.top];
}
void display(stack new)
{
    int i;
    for (i = 0; i <= new.top; i++)
    {
        printf("%d  ", new.arr[i]);
    }
    printf("\n");
}