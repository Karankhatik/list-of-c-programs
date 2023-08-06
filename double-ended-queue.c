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
     Q->front = Q->rear = -1;

     Q->ptr = malloc(sizeof(int)*cap);

     return Q;
}

void insertRear(struct Queue *Q, int data)
{
    if(Q->rear == Q->capacity-1 && Q->front == 0 || Q->front == Q->rear + 1)
    printf("\nOVerFlow");
    else if(Q->rear == -1 && Q->front == -1)
    {
        Q->rear = 0;
        Q->ptr[Q->rear] = data;
    }
    else if(Q->rear == Q->capacity -1)
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

void insertFront(struct Queue *Q, int data)
{
    if(Q->rear == Q->capacity - 1 && Q->front == 0 || Q->front == Q->rear + 1)
    printf("\noverFlow!!!!");
    else if(Q->front == -1 && Q->rear == -1)
    {       
        Q->front = Q->capacity - 1;
        Q->ptr[Q->front] = data;
    }
    else if(Q->front == 0)
    {
        Q->front == Q->capacity - 1;
        Q->ptr[Q->front] = data;

    }
    else
    {
        Q->front -= 1;
        Q->ptr[Q->front] = data;
    }
}

void removeRear(struct Queue *Q)
{
    if(Q->rear == -1 && Q->front == -1)
    {
        printf("\nList is Empty");
    }
    else if(Q->rear == Q->front)
    {
        printf("Deleted Element From rear : %d",Q->ptr[Q->rear]);

        Q->rear = -1;
        Q->front = -1;
    }
    else if(Q->rear == 0)
    {
        printf("\nDeleted Element From rear : %d",Q->ptr[Q->rear]);
        Q->rear = Q->capacity -1;
    }
    else
    {
        printf("Deleted Element From Queue %d",Q->ptr[Q->rear]);
        Q->rear +=1;
    }
}

void removeFront(struct Queue *Q)
{
    if(Q->front == -1 && Q->rear == -1)
    printf("\nQueue is Empty");
    else if(Q->rear == Q->front)
    {
        printf("\nDeleted Element from Queue : %d",Q->ptr[Q->front]);
        Q->rear = -1;
        Q->front = -1;
    }
    else if(Q->front == Q->capacity -1)
    {
        printf("Deleted element from From %d",Q->ptr[Q->front]);
        Q->front = 0;
    }
    else 
    {
        printf("Deleted element from Queue %d",Q->ptr[Q->front]);
        Q->rear -= 1;
    }
}

int main()
{
    struct Queue *Q;
    Q = createQueue(6);

    int data,ch;

    while(1)
    {
        printf("\n1.Insert At rear");
        printf("\n2.Insert At Front");
        printf("\n3.Deletion from rear");
        printf("\n4.deletion from front");
        printf("\n5.Exit");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(1)
        {
            case 1:
            printf("\nEnter the data : ");
            scanf("%d",&data);

            insertRear(Q,data);
            break;

            case 2:
            printf("\nEnter the data : ");
            scanf("%d",&data);

            insertFront(Q,data);
            break;

            case 3:
            removeRear(Q);
            break;

            case 4:
            removeFront(Q);
            break;

            case 5:
            exit(0);

            default:
            printf("\nInvalid Choice");
        }
    }
}