#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev; 
    int data;
    struct node *next;

};
struct node *head=NULL,*tail=NULL,*p;

void create()
{
    int n;
    printf("Enter number of nodes ");
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++)
    {
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->next=NULL;
        printf("enter the node ");
        scanf("%d",&temp->data);
        temp->prev=temp->next=NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            
            temp->prev=tail;
            tail=temp;
        }
        
    }
    
}
void view(){
    printf("\n");
    struct node *trav;
    
    trav=head;
    while(trav!=NULL){

printf("%d",trav->data);
trav=trav->next;
}

}
void sort(){
    struct node *i,*j;
    int num;
    for(i=head;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next)
        {
        if(i->data>j->data){
        num=j->data;
        j->data=i->data;
        i->data=num;
    }
    }
    
}

}
int main(){

    create();
    view();
    sort();
    view();
       
   
   }
    
