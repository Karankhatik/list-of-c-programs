#include<stdio.h>
int main()
{
    int n,x,y=1,z,sum=0;
    printf("Enter the number : ");
    scanf("%d",&n);
    while(n)
    {
        x = n%10;
        sum = (sum +x)*10; 
        n=n/10;

    }
    printf("Reverse of a number : %d",sum/10);
    return 0;
}