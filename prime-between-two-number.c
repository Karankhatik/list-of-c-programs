#include<stdio.h>
int main()
{
    int i,start,last,x;
    printf("Start of prime number : ");
    scanf("%d",&start);
    printf("last number off nth series : ");
    scanf("%d",&last);
    for(x=start;;x++)
    {
        for(i=2;i<last;i++)
        {
            if(x%i==0)
            break;
        }
        if(x==i)
        {
         printf("%d ",x);
        }
    }
    return 0;
}