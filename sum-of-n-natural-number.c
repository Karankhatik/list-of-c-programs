#include<stdio.h>
int sum(int n);

void main()
{
    int a,s;
    printf("Enter the number : ");
    scanf("%d",&a);
    s = sum(a);
    printf("Sum of n natural number : %d",s);
    

}
int sum(int n)
{
    int i=1,x=0;
    while(n)
    {
       x = x +i;
       i++;
       n--;
    }
    return x;
}