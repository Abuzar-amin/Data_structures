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

// Function to sort the circular linked list using Insertion Sort
void sort() {
    if (head == NULL || head->next == head) {
        // List is empty or has only one element, no need to sort
        return;
    }

    struct node *sorted = NULL;
    struct node *current = head;

    // Loop to process each node
    do {
        struct node *next = current->next;

        if (sorted == NULL || sorted->data >= current->data) {
            // Insert at the beginning of the sorted list
            current->next = sorted ? sorted : current;
            sorted = current;
        } else {
            // Find the proper location to insert the current node
            struct node *trav = sorted;
            while (trav->next != sorted && trav->next->data < current->data) {
                trav = trav->next;
            }
            current->next = trav->next;
            trav->next = current;
        }
        current = next;
    } while (current != head);

    // Find the tail of the sorted list
    tail = sorted;
    while (tail->next != sorted) {
        tail = tail->next;
    }

    // Complete the circle
    tail->next = sorted;
    head = sorted;
}

int main() {
    create();
    printf("Before sorting:\n");
    view();
    
    sort();
    printf("After sorting:\n");
    view();
    
    return 0;
}
