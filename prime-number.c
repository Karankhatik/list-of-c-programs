#include<stdio.h>
int main()
{
    int i,x,n;
    printf("Enter nth term of prime number : ");
    scanf("%d",&n);
    for(x=2;;x++)
    {
        for(i=2;i<n;i++)
        {
            if(x%i==0)
            break;
        }
        if(x==i)
        printf("%d ",x);
    }

    return 0;
}