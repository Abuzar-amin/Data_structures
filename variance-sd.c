#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter value of n ");
    scanf("%d",&n);
    float A[n];
    int i=0;
    printf("\nEnter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&A[i]);
    }
    float sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+A[i];
    }
    float avg=sum/n;
    for(i=0;i<n;i++)
    {
        A[i]=A[i]-avg;
    }
    float num=0;
    for(i=0;i<n;i++)
    {
      A[i]=A[i]*A[i]; 
    }
    for(i=0;i<n;i++)
    {
        num=num+A[i];
    }
    printf("\n%f is Standard deviation",sqrt(num/n));
    printf("\n%f is Variance",(num/n));

}
