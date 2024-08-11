#include<stdio.h>
int main()
{
    int len1=0,len2=0;
    char A[10],B[10];
    printf("Enter 1st string ");
    scanf("%s",A);
    printf("\n");
    printf("Enter 2nd string ");
    scanf("%s",B);
    while(A[len1]!='\0')
    {
        len1++;
    }
    while(B[len2]!=0)
    {
        len2++;
    }
    if(len1>len2)
    {
        printf("String 1 is bigger\n");
        
    }
    else if(len2>len1)
    {
        printf("String 2 is bigger\n");
        
    }
    else
    printf("Both strings are equal");
}
