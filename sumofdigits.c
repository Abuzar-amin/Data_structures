#include<stdio.h>
int sum(int n)
{
    if(n==0)
    return 0;
    return(n%10+sum(n/10));
}
int main()
{
    int n=521,r;
    r=sum(521);
    printf("%d is sum",r);
}
