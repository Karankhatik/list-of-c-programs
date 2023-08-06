#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int capacity;
    int top;
    int *ptr;
};

struct stack * createStack(int cap)
{
    struct stack *s;

    s = malloc(sizeof(struct stack));

    s->capacity = cap;

    s->top = -1;

    s->ptr = malloc(sizeof(int)*cap);

    return s;
}

void Push(struct stack *s, int data)
{
    if(s->top == s->capacity - 1)
    printf("OverFlow");

    else
    {
        s->top += 1;

        s->ptr[s->top] = data;
    }
}

int Pop(struct stack *s)
{
    int data;

    if( s->top < 0 )
    printf("\nUnderFlow");

    else
    {
        data = s->ptr[s->top];

        s->top -= 1;

        return data;
    }
}

void Peek(struct stack *s)
{
    if(s->top < 0)
    printf("\nElement not present");

    else
    printf("Peek Element : %d",s->ptr[s->top]);

}




int main()
{
    struct stack *s;
    int data, ch;
    s = createStack(5);


    while(1)
    {
        printf("\n1.Push An element to stack");
        printf("\n2.Pop An Element of the stack");
        printf("\n3.Peek Element in the Array");
        printf("\n4.Exit");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("\nEnter the data : ");
            scanf("%d",&data);

            Push(s,data);
            break;

            case 2:

            printf("Deleted Element : %d",Pop(s));
            break;

            case 3:
            Peek(s);
            break;

            case 4:
            exit(0);

            default:
            printf("\nInvalid choice");

        }

    }
}