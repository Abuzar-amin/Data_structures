#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *next, *prev;
};

struct node *head = NULL, *tail = NULL;

void create()
{
    int n, i;
    struct node *temp;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) 
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter node: ");
        scanf("%d", &temp->data);
        temp->prev = temp->next = NULL;

        if(head == NULL)
        {
            head = tail = temp;
            head->next = head->prev = head; // Making it circular
        } else
        {
            tail->next = temp;
            temp->prev = tail;
            temp->next = head;
            head->prev = temp;
            tail = temp;
        }
    }
}

void view()
{
    if (head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }

    struct node *trav = head;
    printf("\nCircular Doubly Linked List: ");
    
    do
    {
        printf("%d ", trav->data);
        trav = trav->next;
    } while(trav != head);
    printf("\n");
}

void insert() 
{
    int element, item;
    struct node *trav = head, *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter item you want to add: ");
    scanf("%d", &item);
    printf("Enter element after which you want to add item: ");
    scanf("%d", &element);
    
    do
    {
        if (trav->data == element) 
        {
            temp->data = item;
            temp->prev = trav;
            temp->next = trav->next;
            trav->next->prev = temp;
            trav->next = temp;
            
            if(trav == tail) {
                tail = temp;
            }
            printf("Element %d inserted successfully.\n", item);
            return;
        }
        trav = trav->next;
    } while(trav != head);

    printf("Element %d not found.\n", element);
}

void delete() 
{
    int element;
    printf("Enter element you want to delete: ");
    scanf("%d", &element);
    struct node *trav = head;
    struct node *temp;

    if(head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    do
    {
        if(trav->data == element)
        {
            temp = trav;

            if(trav == head && trav == tail) 
            { 
                head = tail = NULL;
                free(temp);
                printf("Element %d deleted successfully.\n", element);
                return;
            }

            if(trav == head) 
            { 
                head = trav->next;
                head->prev = tail;
                tail->next = head;
            } 
            else if(trav == tail)
            {
                tail = trav->prev;
                tail->next = head;
                head->prev = tail;
            } 
            else 
            { 
                trav->prev->next = trav->next;
                trav->next->prev = trav->prev;
            }

            trav = trav->next;
            free(temp);
            return;
        } else {
            trav = trav->next;
        }
    } 
}

int main() {
    create();
    view();
    
    // insert();
    // view();
    delete();
    view();
    
    return 0;
}
