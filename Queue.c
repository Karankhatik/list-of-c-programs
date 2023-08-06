#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int capacity;
    int front,rear;
    int *ptr;
};

struct Queue * createQueue(int cap)
{
    struct Queue *Q;

    Q = malloc(sizeof(struct Queue));

    Q->capacity = cap;
    Q->front = -1;
    Q->rear = -1;

    Q->ptr = malloc(sizeof(int)*cap); 
}

void insertion(struct Queue *Q,int data)
{
    if(Q->rear == Q->capacity -1 && Q->front == 0 || Q->rear == Q->front -1 )
    printf("\nOverFlow");
    else if(Q->rear == -1)
    {
        Q->rear = 0;
        Q->front = 0;
        Q->ptr[Q->rear] = data;
    }
    else if(Q->rear == Q->capacity - 1)
    {
        Q->rear = 0;
        Q->ptr[Q->rear] = data;
    }
    else
    {
        Q->rear += 1;
        Q->ptr[Q->rear] = data;
    }
}

void Deletion(struct Queue *Q)
{
    if(Q->front == -1)
    printf("\nUnder Flow");
    else if(Q->front == Q->rear)
    {
        Q->front = -1;
        Q->rear = -1;
    }
    else if(Q->front == Q->capacity -1)
    {
        Q->front = 0;
    }
    else
    {
        Q->front += 1;
    }
}

void peek(struct Queue *Q)
{
    printf("\nPeek : %d",Q->ptr[Q->rear]);
}

void Display(struct Queue *Q)
{
    if (Q->front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (Q->rear >= Q->front)
    {
        for (int i = Q->front; i <= Q->rear; i++)
            printf("%d ",Q->ptr[i]);
    }
    else
    {
        for (int i = Q->front; i < Q->capacity; i++)
            printf("%d ", Q->ptr[i]);
 
        for (int i = 0; i <= Q->rear; i++)
            printf("%d ", Q->ptr[i]);
    }
}

int main()
{
    struct Queue *Q;
    
    int data,ch;

    Q = createQueue(5);

    while(1)
    {
        printf("\n1.Inserrtion in Queue");
        printf("\n2.Deletion in Queue");
        printf("\n3.Peek Element in Queue");
        printf("\n4.Display Queue");
        printf("\n5.Exit");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("Enter the data : ");
            scanf("%d",&data);
            
            insertion(Q,data);
            break;

            case 2:
            Deletion(Q);
            break;

            case 3:
            peek(Q);
            break;

            case 4:
            Display(Q);
            break;

            case 5:
            exit(0);

            default:
            printf("\nInvalid Choice");
        }

    }

     
}