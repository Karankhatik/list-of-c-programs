#include <stdio.h>
#include <stdlib.h>

struct Array 
{
    int capacity;
    int lastindex;
    int *ptr;
};

struct Array * createArray(int cap)
{
    struct Array *arr;

    arr = (struct Array *) malloc(sizeof(struct Array));

    arr->capacity = cap;

    arr->lastindex = -1;

    arr->ptr = malloc(sizeof(int)*cap);

    return arr;
}

void Append(struct Array *arr, int data)
{
    if(arr->lastindex == arr->capacity - 1)
    printf("\nOverFlow");

    else
    {
        arr->lastindex += 1;
        arr->ptr[arr->lastindex] = data;
    }
}

void Insert(struct Array *arr, int data, int index)
{
    int i;

    if(index < 0 || index > arr->lastindex + 1)
    printf("\nIndex is not valid");
    else if(arr->lastindex == arr->capacity - 1)
    printf("Over Flow");
    else
    {
        for( i = arr->lastindex; i >= index; i--)
        arr->ptr[i+1] = arr->ptr[i];
    }
    arr->lastindex += 1;
    arr->ptr[index] = data;
}

void Count(struct Array *arr)
{
    printf("\nTotal Elements in YOur Array : %d",arr->lastindex+1);
}

void GetItem(struct Array *arr, int index)
{
    if(index < 0 || index > arr->capacity - 1)
    printf("\nIndex Is not Valid");

    else
    {
        printf("Index of Your Array : %d",arr->ptr[index]);
    }
}

void Delete(struct Array *arr, int index)
{
    int i;

    if(index < 0 || index > arr->lastindex + 1)
    printf("\nIndex is not valid ");
    
    else
    {
        for(i = index; i <= arr->lastindex; i++)
        {
            arr->ptr[i] = arr->ptr[i+1];
        }
        arr->lastindex -= 1;
    }
}

void EditItem(struct Array *arr,int data, int index)
{
    if(index < 0 || index > arr->capacity - 1)
    printf("\nIndex is Not valid ");
    else
    arr->ptr[index] = data;
}

int search(struct Array *arr, int data)
{
        
   for(int i = 0; i <= arr->lastindex; i++)
   {
       if(arr->ptr[arr->lastindex] == data)
       return data;
   }
   return 0;
}

void Display(struct Array *arr)
{
    if(arr->lastindex < 0)
    printf("Data not present");

    printf("\nHere is your : ");
    for(int i = 0; i <= arr->lastindex; i++ )
    {
        printf("%d ",arr->ptr[i]);

    }

}

int main()
{
    struct Array *arr;
    int data, ch, index,r;

    arr = createArray(6);

    while(1)
    {
        printf("\n1.Append An item");
        printf("\n2.Insert an Item");
        printf("\n3.Count total items present");
        printf("\n4.Get item at givn Index");
        printf("\n5.Delete an item from a given index");
        printf("\n6.Edit an Item");
        printf("\n7.Search an Item");
        printf("\n8.Display An item");

        printf("\n\n Enter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            printf("\nEnter the data : ");
            scanf("%d",&data);

            Append(arr,data);
            break;

            case 2:
            printf("\nEnter the data and also index: ");
            scanf("%d%d",&data,&index);

            Insert(arr,data,index);
            break;

            case 3:
            Count(arr);
            break;

            case 4:
            printf("\nEnter the Index : ");
            scanf("%d",&index);

            GetItem(arr,index);
            break;

            case 5:
            printf("\nEnter the Index : ");
            scanf("%d",&index);

            Delete(arr,index);
            break;

            case 6:
            printf("\nEnter the data and  index : ");
            scanf("%d%d",&data,&index);

            EditItem(arr,data,index);
            break;

            case 7:
            printf("Enter the data : ");
            scanf("%d",&data);

            r = search(arr,data);

            if(r = 0)
            printf("Data is not present");
            else
            printf("Data is present");
            break;

            case 8:
            Display(arr);
            break;
        }

    }
}