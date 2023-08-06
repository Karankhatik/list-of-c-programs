#include<stdio.h>
void even(int n);
void main()
{
    int a;
    printf("Enter the nth term of even number : ");
    scanf("%d",&a);
    even(a);


}
void even(int n)
{
    int i=2;
    while(n)
    {
        if(i%2==0)
        printf("%d ",i);
        i++;
        n--;
    }
}