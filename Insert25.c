#include<stdio.h>
int main()
{
    int n, element, item, index, i;
    int A[10];
    printf("Enter size of array\n");
    scanf("%d",&n);
    A[n];
    printf("enter elements of array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("enter element after which you want to insert item\t");
    scanf("%d",&element);
    printf("enter item you want to add\t");
    scanf("%d",&item);
    for(i=0;i<n;i++)
    {
        if(A[i]==element)
        {
            index=i;
            break;
        }
    }
    n=n+1;
    for(i=n;i>index;i--)
    {
        A[i]=A[i-1];
    }
    A[index+1]=item;
    printf("MODIFIED ARRAY IS: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",A[i]);
    }

}
