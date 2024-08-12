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
    int min=A[0];
    for(i=0;i<n;i++)
    {
        if(A[i]<min)
        min=A[i];
       
    }
    printf("Smallest no. is %d",min);
    
    
}
