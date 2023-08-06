#include<stdio.h>
int main()
{
    int n,i,num=1,x=0;
    printf("Enter the number : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        x = num*num + x;
        num++;

    }
    printf("SUM OF SQUARE OF N NATURAL NUMBER : %d",x);

    return 0;
}