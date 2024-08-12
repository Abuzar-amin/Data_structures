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
    printf("\nEven numbers are:\n ");
    for(i=0;i<n;i++)
    {
        if(A[i]%2==0)
        printf("%d ",A[i]);
        
    }
    
    
}
