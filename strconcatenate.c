#include<stdio.h>
int main()
{
    char s1[20],s2[10];
    printf("Enter 1st string ");
    scanf("%s",s1);
    printf("\n");
    printf("Enter 2nd string ");
    scanf("%s",s2);
    
    int len1=0,i=0;
    
    while(s1[len1]!='\0')
    {
        len1++;
    }
    while(s2[i]!='\0')
    {
        s1[len1+i]=s2[i];
        i++;
    }
 
    s1[len1+i]='\0';
    printf("\n");
    printf("Concatenated string is %s", s1);

}
