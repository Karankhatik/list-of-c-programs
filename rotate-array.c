#include <stdio.h>
#include <stdlib.h>

void rotate(int arr[], int size, int r)
{
    int i,temp;

    if(r == -1)
    {
        temp = arr[0];

        for(i = 0; i < size; i++)
        arr[i] = arr[i+1];

        arr[size-1] = temp;
        printf("Rotated Array : ");
       for( i = 0; i < size; i++)
       printf("%d ",arr[i]);
    }

    if(r == 1)
    {
        temp = arr[size-1];
        for(i = size; i > 0; i--)
        arr[i] = arr[i-1];

        arr[0] = temp;

        printf("Rotated Array : ");
       for( i = 0; i < size; i++)
       printf("%d ",arr[i]);

    }
}

int main()
{
    int arr[5],r;

    printf("Enter the value of Arrays :\n ");

    for(int i = 0; i < 5; i++)
    {
        printf("Enter at index %d : ",i);
        scanf("%d",&arr[i]);
    }

    printf("Enter -1 for left rotate and +1 for Right rotate :");
    scanf("%d",&r);

    rotate(arr,5,r);


}