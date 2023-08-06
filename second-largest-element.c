#include<stdio.h>
int secondLargest(int a[],int size)
{
    int i,j,temp;

    for(i = 0; i < size; i++)
    {
        for(j = i+1; j < size; j++)
        {
            if(a[i]>a[j])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = a[j];
            }

        }
    }
    return a[size-2];

}
int main()
{
    int a[5],i;

    printf("Enter the array: \n");
    for(i = 0; i < 5; i++)
    scanf("%d",&a[i]);

    printf("Second largest element : %d",secondLargest(a,5));
}