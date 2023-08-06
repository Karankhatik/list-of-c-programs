#include <stdio.h>

void BubbleSort(int A[], int size)
{
    int i, temp, r;

    for(r = 1; r < size; r++)
    {
        for(i = 0; i < size - r; i++)
        {
            if(A[i] > A[i+1])
            {
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;               
            }
        }
    }

     printf("BS Sorted Array : ");
    for(i = 0; i < size; i++)
    printf(" %d",A[i]);
}

void MBS(int A[], int size)
{
    int i, temp, r, flag = 0;

    for(r = 1; r < size; r++)
    {
        for(i = 0,flag = 0; i < size - r; i++)
        {
            if(A[i] > A[i+1])
            {
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                flag = 1;               
            }

            if(flag == 0)
            break;

        }
    }

    printf("\n MBS Sorted Array : ");
    for(i = 0; i < size; i++)
    printf(" %d",A[i]);
}

void SelectionSort(int A[], int size)
{
    int i, min, j, k, t;    

    for(i = 0; i  < size; i++)
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

        t = A[i];
        A[i] = A[k];
        A[k] = t;
    }

      printf("\nSS Sorted Array : ");
    for(i = 0; i < size; i++)
    printf(" %d",A[i]);
}

void InsertionSort(int A[], int size)
{
    int i, j, temp;

    for(i = 1; i < size; i++)
    {
        temp = A[i];

        for(j = i - 1; j >= 0; j--)
        {
            if(A[j] > temp)
            A[j+1] = A[j];
            else 
            break;             
        }
        A[j + 1] = temp;
    }

    printf("\nSorted Array : ");
    for(i = 0; i < size; i++)
    printf(" %d",A[i]);
}



int main()
{
    int size, i;
    
    printf("Enter the size of Array : ");
    scanf("%d",&size);

    int A[size];

    printf("Enter the Array Elements : \n");
    for(i = 0; i < size; i++)
      scanf("%d",&A[i]);

    //   BubbleSort(A,size);

    //   MBS(A,size);

      SelectionSort(A,size);

    //   InsertionSort(A,size);
    
}