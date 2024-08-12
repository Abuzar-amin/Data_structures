#include<stdio.h>
int leucas(int n)
{
    if(n==1 || n==2 || n==3)
    printf("1");
    else
    printf("%d",leucas(n-1)+leucas(n-2)+leucas(n-3));
}
int main()
{
   int n;
   printf("Enter number of terms ");
   scanf("%d",&n);
   leucas(n);
}
