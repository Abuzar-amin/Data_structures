#include<stdio.h>
int main()
{
    char S[100];
    int i;
    printf("Enter a string ");
    scanf("%s",S);
    for(i=0;S[i]!='\0';i++)
    {
        if(S[i]>='a'&&S[i]<='z')
        {
            S[i]=S[i]-32;
        }
    }
    printf("\n");
    printf("String in upper case is %s ",S);
}
