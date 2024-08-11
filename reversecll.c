#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

// Function to create a circular linked list
void create() {
    int n, i;
    struct node *temp;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter node: ");
        scanf("%d", &temp->data);
        temp->next = NULL;

        if(head == NULL) {
            head = tail = temp;
            head->next = head; // Making it circular
        } else {
            tail->next = temp;
            temp->next = head;
            tail = temp;
        }
    }
}

// Function to view the circular linked list
void view() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *trav = head;
    printf("Circular Linked List: ");
    
    do {
        printf("%d ", trav->data);
        trav = trav->next;
    } while(trav != head);
    printf("\n");
}

// Function to reverse the circular linked list
void reverse() {
    if (head == NULL || head->next == head) {
        // List is empty or has only one element, no need to reverse
        return;
    }

    struct node *prev = tail, *current = head, *next = NULL;

    do {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    } while (current != head);

    // Adjusting head and tail pointers
    tail = head;
    head = prev;

    // Reconnect tail to the new head to maintain circularity
    tail->next = head;
}

int main() {
    create();
    printf("Original list:\n");
    view();
    
    reverse();
    printf("Reversed list:\n");
    view();
    
    return 0;
}
