#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next, *prev;
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
        temp->prev = temp->next = NULL;

        if (head == NULL) {
            head = tail = temp;
            head->next = head->prev = head;
        } else {
            tail->next = temp;
            temp->prev = tail;
            temp->next = head;
            head->prev = temp;
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
    printf("\nCircular Doubly Linked List: ");

    while (trav->next != head) {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("%d\n", trav->data); // Print the last node
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
            temp->prev = trav;
            temp->next = trav->next;
            trav->next->prev = temp;
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
        temp->prev = trav;
        temp->next = head;
        trav->next = temp;
        head->prev = temp;
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

    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while (trav->next != head) {
        if (trav->data == element) {
            if (trav == head) {
                head = trav->next;
                head->prev = tail;
                tail->next = head;
            } else {
                trav->prev->next = trav->next;
                trav->next->prev = trav->prev;
            }

            free(trav);
            return;
        }
        trav = trav->next;
    }

   
    if (trav->data == element) {
        if (trav == head && trav == tail) { 
            head = tail = NULL;
        } else {
            tail = trav->prev;
            tail->next = head;
            head->prev = tail;
        }

        free(trav);
    } else {
        printf("Element %d not found.\n", element);
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
