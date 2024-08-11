#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
struct node *head=NULL, *tail=NULL;
void create()
{
    int n,i=0;
    struct node *temp;
    printf("Enter number of nodes ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter node ");
        scanf("%d",&temp->data);
        temp->prev=temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
    }
}
void view()
{
    printf("\n");
    struct node *trav=head;
    while(trav!=NULL)
    {
        printf("%d ",trav->data);
        trav=trav->next;
        
    }

}
void insert()
{
    int element,item;
    struct node*trav=head,*temp=(struct node *)malloc(sizeof(struct node));
    printf("Enter item you want to add ");
    scanf("%d",&item);
    printf("Enter element after which you want to add item ");
    scanf("%d",&element);
    while(trav->data!=element)
    {
        trav=trav->next;
    }
    temp->data=item;
    temp->prev = trav;
    temp->next = trav->next;
    
    if(trav->next != NULL) 
    {  
        trav->next->prev = temp;
    } 
    else
    {
        
        tail = temp;
    }
    
    trav->next = temp;
    if(trav==tail)
    {
        tail=tail->next;
    }
}

void delete()
{
    int element;
    printf("Enter element you want to delete: ");
    scanf("%d", &element);
    struct node *trav = head;
    struct node *temp;

     

    while (trav != NULL)
    {
        if (trav->data == element)
        {
            
            temp = trav;

           
            if (trav == head) 
            {
                head = trav->next;
                if (head != NULL) 
                {
                    head->prev = NULL;
                } else 
                {
                    
                    tail = NULL;
                }
            } 
            
            else if (trav == tail) 
            {
                tail = trav->prev;
                tail->next = NULL;
            } 
            
            else 
            {
                trav->prev->next = trav->next;
                trav->next->prev = trav->prev;
            }

            
            trav = trav->next;

            
            free(temp);
        } 
        else 
        {

            trav = trav->next;
        }
    }
}

int main()
{
    create();
    view();
    //insert();
    delete();
    view();
}
