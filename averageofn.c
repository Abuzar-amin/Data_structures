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
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+A[i];
    }
    printf("Average is %d",sum/n);
    
}
