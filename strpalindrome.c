#include<stdio.h>
int main()
{
    char s1[10],s2[10];
    printf("Enter a string ");
    scanf("%s",s1);
    int len1=0,len2=0,flag=0;
    while(s1[len1]!='\0')
    {
        len1++;
    }
    for(int i=0;i<len1;i++)
    {
        if(s1[i]!=s1[len1-1-i])
        {
            flag=1;
            break;
        }
        
    }
    printf("\n");
    if(flag==1)
    {
        printf("Not a palindrome");
        
    }
    else
    {
        printf("Given string is a palindrome");
    }
}
