#include<stdio.h>
int main()
{
    int n,i,x;
    printf("Enter the number : ");
    scanf("%d",&n);
    x = 1;
    for(i=2;i<n;i++)
    {
      if(n%i==0)   
      x = 0;
    }
if(x==1)
printf("PRIME NUMBER ");
if(x==0)
printf("NOT PRIME NUMBER");
   

    return 0;

}