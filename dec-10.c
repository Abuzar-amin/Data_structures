#include<stdio.h>
void convert(int n, int b)
{
    int r;
    if(n==0)
    printf("0");
    else
    {
        r=n%b;
        convert(n/b,b);
        printf("%d",r);
    }
}
int main()
{
    int n,b;
    printf("Enter a decimal number ");
    scanf("%d",&n);
    printf("\n Enter a base less than 10 ");
    scanf("%d",&b);
    convert(n,b);
    
    
  

}
