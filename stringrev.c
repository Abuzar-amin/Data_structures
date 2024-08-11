#include<stdio.h>
int main()
{
    char S[100];
    int i,len=0;
    printf("Enter a string ");
    scanf("%s",S);
    while(S[len]!='\0')
    {
        len++;
    }
    for(i=0;i<(len-1)/2;i++)
    {
        char c=S[i];
        S[i]=S[(len-1-i)];
        S[(len-1-i)]=c;
    }
    printf("Reversed string is %s ",S);
}
