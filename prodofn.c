#include<stdio.h>
int main()
{
    int n;
    printf("Enter value of n ");
    scanf("%d",&n);
    int A[n];
    int i=0;
    printf("\nEnter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int product=1;
    for(i=0;i<n;i++)
    {
        product=product*A[i];
    }
    printf("Product is %d",product);
    
}
