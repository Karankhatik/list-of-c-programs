#include<stdio.h>
int main()
{
    int i,x=0,n=1;
    printf("Enter the nth number : ");
    scanf("%d",&i);
    while(i)
    {
  
        x = x+n;
        n = n+2;
        
        i--;
    }
    printf("addition of nth odd number number : %d",x);

    return 0;
}