#include <stdio.h>

int Quick(int A[],int l, int u)
{
    int loc = l, temp,left = l;
    int right = u;


    while(left < right)
    {
        while(left < right && A[loc] < A[right])
        right--;
        if(A[loc] > A[right])
        {
            temp = A[loc];
            A[loc] = A[right];
            A[right] = temp;
            loc = right;
        }

        while(left < right && A[loc] > A[left])
        left++;
        if(A[loc] < A[left])
        {
            temp = A[loc];
            A[loc] = A[left];
            A[left] = temp;
            loc = left;
        }
    }
    return loc;
}

void QuickSort(int A[], int l, int u)
{
    int loc;

    loc = Quick(A, l , u);

    if( l < loc - 1)
    QuickSort(A, l, loc - 1);

    if(loc + 1 < u)
    QuickSort(A,loc + 1, u);
}

int main()
{
    int size,i;

    printf("Enter the size of Array : ");
    scanf("%d",&size);

    int A[size];

    printf("Enter the value of Array : \n");
    for(i = 0; i < size; i++)
    scanf("%d",&A[i]);

    QuickSort(A,0,size-1);
    
    printf("Sorted Array : ");
    for(i = 0; i < size; i++)
    printf(" %d",A[i]);

    

    
}