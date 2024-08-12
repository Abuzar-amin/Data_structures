#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void create() {
    int n, i;
    struct node *temp;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter node: ");
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (head == NULL) {
            head = tail = temp;
            head->next = head; 
        } else {
            tail->next = temp;
            temp->next = head;
            tail = temp;
        }
    }
}

void view() {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }

    struct node *trav = head;
    printf("\nCircular Linked List: ");

    while (trav->next != head) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("%d\n", trav->data);  
}

void insert() {
    int element, item;
    struct node *trav = head, *temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter item you want to add: ");
    scanf("%d", &item);
    printf("Enter element after which you want to add item: ");
    scanf("%d", &element);

    while (trav->next != head) {
        if (trav->data == element) {
            temp->data = item;
            temp->next = trav->next;
            trav->next = temp;

            if (trav == tail) {
                tail = temp;
            }

            return;
        }
        trav = trav->next;
    }

    
    if (trav->data == element) {
        temp->data = item;
        temp->next = head;
        trav->next = temp;
        tail = temp;
    } else {
        printf("Element %d not found.\n", element);
    }
}

void delete() {
    int element;
    printf("Enter element you want to delete: ");
    scanf("%d", &element);
    struct node *trav = head;
    while (trav->next != head && trav->next->data != element) {
        trav = trav->next;
    }

    if (trav->next->data == element) {
        struct node *temp = trav->next;
        trav->next = temp->next;

        free(temp);
    }
}

int main() {
    create();
    view();

    insert();
    view();

    delete();
    view();

    return 0;
}

