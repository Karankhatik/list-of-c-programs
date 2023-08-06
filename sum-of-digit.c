#include<stdio.h>
int main()
{
    int x,n,sum=0;
    printf("Enter the number : ");
    scanf("%d",&n);
    while(n)
    {
        x = n%10;
        sum = sum+x;
        n = n/10;
    }
    printf("sum of given digit : %d",sum);

    return 0;
}