#include<stdio.h>
void hexa(int n)
{
    int r;
    if(n==0)
    printf("0");
    else
    {
        r=n%16;
        hexa(n/16);
        if(r==10)
        printf("A");
        else if(r==11)
        printf("B");
        else if(r==12)
        printf("C");
        else if(r==13)
        printf("D");
        else if(r==14)
        printf("E");
        else if(r==15)
        printf("F");
        else
        printf("%d",r);
    }
}
int main()
{
    int n;
    printf("Enter a decimal number ");
    scanf("%d",&n);
    hexa(n);
  

}
