# include <stdio.h>
# include <string.h>

struct book
{
    char name[20];
    char author[20];
    char publisher[20];
    int edition;
    int pages;
    struct book *next;
}b1,b2,b3;



int main()
{
    strcpy(b1.name, "ABC");
    strcpy(b1.author, "ZZZ");
    strcpy(b1.publisher, "PQR");
    b1.edition = 2001;
    b1.pages = 250;
    b1.next = &b2;

    strcpy(b2.name, "XYZ");
    strcpy(b2.author, "SSS");
    strcpy(b2.publisher, "OOO");
    b2.edition = 2008;
    b2.pages = 230;
    b2.next = &b3;

    strcpy(b3.name, "RTD");
    strcpy(b3.author, "CDW");
    strcpy(b3.publisher, "AAA");
    b3.edition = 1857;
    b3.pages = 400;
    b3.next = NULL;

    printf("Details of Book 1 are:\n");
    printf("Name:\t%s\n", b1.name);
    printf("Author:\t%s\n", b1.author);
    printf("Publisher:\t%s\n", b1.publisher);
    printf("Pages:\t%d\n", b1.pages);
    printf("Edition:\t%d\n", b1.edition);
    printf("\n\n\n");

    printf("Details of Book 2 are:\n");
    printf("Name:\t%s\n", b1.next->name);
    printf("Author:\t%s\n", b1.next->author);
    printf("Publisher:\t%s\n", b1.next->publisher);
    printf("Pages:\t%d\n", b1.next->pages);
    printf("Edition:\t%d\n", b1.next->edition);
    printf("\n\n\n");

    printf("Details of Book 3 are:\n");
    printf("Name:\t%s\n", b1.next->next->name);
    printf("Author:\t%s\n", b1.next->next->author);
    printf("Publisher:\t%s\n", b1.next->next->publisher);
    printf("Pages:\t%d\n", b1.next->next->pages);
    printf("Edition:\t%d\n", b1.next->next->edition);
    printf("\n\n\n");



}
