#include <stdio.h>

void insert_in_heap(int heap[], int *hs, int data)
{
    int index , paraindex;
    *hs = *hs + 1;
    
    index = *hs - 1;

    while(index > 0)
    {
        paraindex = (index - 1)/2;

        if(data > heap[paraindex])
        heap[index] = heap[paraindex];
        else
        break;
        
        index = paraindex;
    }
    heap[index] = data;

}

int deleteFromHeap(int heap[], int *hs)
{
    int index = 0, leftindex, rightindex;
    int item = heap[0];
    int temp = heap[*hs - 1];
    *hs = *hs - 1;

    while(index <= *hs -1)
    {
        leftindex = 2*index + 1;
        rightindex = 2*index + 2;

        if(leftindex > *hs - 1)
        break;
        if(rightindex > *hs - 1)
        {
            if(temp < heap[leftindex])
            heap[index] = heap[leftindex];
            else
            break;
            index = leftindex;
        }
        if(heap[leftindex] > heap[rightindex])
        {
            if(temp < heap[leftindex])
            heap[index] = heap[leftindex];
            else
            break;
            index = leftindex;
        }
        else
        {
            if(temp < heap[rightindex])
            heap[index] = heap[rightindex];
            else
            break;
            index = rightindex;
        }
    }
    heap[index] = temp;

    return item;
}

int main()
{
    int a[] = {20,45,38,65,49,40,70};
    int size = 7, heap[20], heapsize = 0, i, j, temp[20], r;

    for(i = 0; i < size; i++)
    insert_in_heap(heap, &heapsize, a[i]);

    printf("AFter insertion : ");
    for(i = 0; i < heapsize; i++ )
    printf(" %d",heap[i]);

      j = heapsize;
      while(heapsize > 0)
    {  
         if(heapsize > 0)
         r = deleteFromHeap(heap,&heapsize);
         j--;
         temp[j] = r;
    }
     
     printf("\nSorted heap : ");
     for(i = 0; i < size; i++)
     printf(" %d",temp[i]);


}