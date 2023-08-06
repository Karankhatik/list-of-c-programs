#include <stdio.h>

void Bubble_Sort(int A[], int size)
{
    int temp, i, r;

    for(r = 1; r < size; r++)
    {
        for(i = 0; i < size - r; i++)
        {
            if(A[i] > A[i+1])
            {
                temp = A[i + 1];
                A[i + 1] = A[i];
                A[i] = temp;
            }
        }
    }
    printf("BS Sorted Array : ");
    for(i = 0; i < size; i++)
    printf(" %d",A[i]);
}

void MBS(int A[], int size)
{
    int temp, r, i, flag;

    for(r = 1; r < size; r++)
    {
        for(i = 0, flag = 0; i < size - r; i++)
        {
            if(A[i] > A[i+1])
            {
                temp = A[i + 1];
                A[i + 1] = A[i];
                A[i] = temp;
                flag = 1;
            }

            if(flag == 0)
            break;
        }        
    }
    printf(" MBS Sorted Array : ");
    for(i = 0; i < size; i++)
    printf(" %d",A[i]);
}

void Selection_Sort(int A[], int size)
{
    int temp , min, i, j, k;    

    for(i = 0; i < size; i ++)
    {
        min = A[i];
        for(j = i + 1; j < size; j++)
        {
            if(min > A[j])
            {
                min = A[j];
                k = j;
            }
        }
        temp = A[k];
        A[k] = A[i];
        A[i] = temp;
        
    }

    printf(" SS Sorted Array : ");
    for(i = 0; i < size; i++)
    printf(" %d",A[i]);
}

void Insertion_Sort(int A[], int size)
{
    int temp, i, j;

    for(i = 1; i < size; i++)
    {
        temp = A[i];

        for(j = i -1; j >= 0; j--)
        {
            if(A[j] > temp)
            A[j + 1] = A[j];
            else 
            break;
        }
        A[j + 1] = temp;

    }

        printf(" IS Sorted Array : ");
        for(i = 0; i < size; i++)
        printf(" %d",A[i]);
}

int main()
{
    int size, i;

    printf("Enter the size of Array : ");
    scanf("%d",&size);

    int A[size];

    printf("Enter the Array value : \n");
    for(i = 0; i < size; i++)
    scanf("%d",&A[i]);

    // Bubble_Sort(A,size);

    // MBS(A,size);

    Selection_Sort(A, size);


    //   Insertion_Sort(A, size);

}