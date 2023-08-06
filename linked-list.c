#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
};

void insertAtFirst(struct node **start, int data)
{
    struct node *n;

    n = malloc(sizeof(struct node));

    n->item = data;
    n->next = *start;
    *start = n;
}

void insertAtLast(struct node **start, int data)
{
    struct node *n,*t;

    n = malloc(sizeof(struct node));

    n->item = data;
    n->next = NULL;

    if(*start == NULL)
    *start = n;
    else
    {
        t = *start;
        while(t->next != NULL)
        t = t->next;

        t->next = n;
    }
}

struct node* search(struct node *start, int data)
{
    while(start)
    {
        if(start->item == data)
        return start;

        start = start->next;
    }
    return NULL;
}

void insertAfter(struct node *r, int data)
{
    struct node *n;

    n = malloc(sizeof(struct node));
     
    n->item = data;
    n->next = r->next;
    r->next = n;
}

void removeFirst(struct node **start)
{
    struct node *temp;

    temp = *start;

    if(*start == NULL)
    printf("\nList is Empty");
    else if(*start == temp->next)
    {
        *start = NULL;
        free(temp);
    }
    else
    {
        *start = temp->next;
        free(temp);
    }
}

void removeLast(struct node **start)
{
    struct node *t1,*t2;

    if(*start == NULL)
    printf("\nList is Empty");
    else
    {
        t1 = *start;

        if(*start == t1->next)
        *start = NULL;
        else
        {
            while(t1->next != NULL)
            {
                t2 = t1;
                t1 = t1->next;
            }
            if(t2->next != NULL)
            t2->next = NULL;

            free(t1);
        }
    }
}

void removeNode(struct node **start, struct node *r)
{
    struct node *t;

    if(*start == NULL)
    printf("\nList is empty");
    else
    {
           t = *start;  
     
        while(t->next != r)
        t = t->next;
        
        t->next = r->next;
     
        free(r);

    } 
}

void viewList(struct node *start)
{
    if(start == NULL)
    printf("\nList Is Empty");
    else
    {
        printf("Here is Your List : ");
        while(start)
        {
            printf("%d ",start->item);
            start = start->next;
        }
    }
}



int main()
{
    struct node *start = NULL, *r;

    int data, ch;

    while(1)
    {
        printf("\n1.Insert List item as First Node");
        printf("\n2.Insert List Item as last node");
        printf("\n3.Insert list item after a given node");
        printf("\n4.Delete first list item");
        printf("\n5.Delte last list item");
        printf("\n6.Delete a particular node");
        printf("\n7.View List Item");

        printf("\n\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("\nEnter the data : ");
            scanf("%d",&data);

            insertAtFirst(&start, data);
            break;

            case 2:
            printf("\nEnter the data : ");
            scanf("%d",&data);
            
            insertAtLast(&start, data);
            break;

            case 3:
            printf("\nEnter the data after you want to insert : ");
            scanf("%d",&data);
            
            r = search(start,data);

            if(r != NULL)
            {
                printf("\nEnter the data : ");
                scanf("%d",&data);

                insertAfter(r, data);                
            }
            else
            printf("\nData Not Found");
            break;

            case 4:
            removeFirst(&start);
            break;

            case 5:
            removeLast(&start);
            break;

            case 6:
            printf("\nEnter the node : ");
            scanf("%d",&data);

            r = search(start, data);

            if(r != NULL)
            {
                removeNode(&start,r);
            }
            else
            printf("\nNode Not Found");
            break;

            case 7:
            viewList(start);
            break;


        }
    }


}