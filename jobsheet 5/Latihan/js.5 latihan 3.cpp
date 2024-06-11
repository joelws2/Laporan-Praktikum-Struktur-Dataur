#include <stdio.h>
#include <stdlib.h>

// Structure of the node
struct Node {
    int data;
    struct Node *next; // Pointer to next node
    struct Node *prev; // Pointer to previous node
};

// Function to insert a node at the end of a circular doubly linked list
void insertEnd(struct Node** start, int value) {
    // If the list is empty, create a single node circular and doubly list
    if (*start == NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }

    // If list is not empty, find last node
    struct Node *last = (*start)->prev;

    // Create Node dynamically
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;

    // Start is going to be next of new_node
    new_node->next = *start;

    // Make new node previous of start
    (*start)->prev = new_node;

    // Make last previous of new node
    new_node->prev = last;

    // Make new node next of old last
    last->next = new_node;
}

// Function to display nodes in a circular doubly linked list
void display(struct Node* start) {
    struct Node *temp = start;

    printf("\nTraversal in forward direction \n");
    while (temp->next != start) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);

    printf("\nTraversal in reverse direction \n");
    struct Node *last = start->prev;
    temp = last;
    while (temp->prev != last) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}

int main() {
    // Start with the empty list
    struct Node* start = NULL;

    // Insert nodes into the list
    insertEnd(&start, 5);
    insertEnd(&start, 8);
    insertEnd(&start, 9);
    insertEnd(&start, 3);

    // Display the created circular doubly linked list
    printf("Created circular doubly linked list is: ");
    display(start);

    return 0;
}
