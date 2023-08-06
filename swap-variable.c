#include<stdio.h>
int main()
{
    int x,y,z;
    printf("Enter two numbers");
    scanf("%d%d",&x,&y);
    z=x;
    x=y;
    y=z;
    printf(" x = %d y = %d",x,y);

    return 0;
}