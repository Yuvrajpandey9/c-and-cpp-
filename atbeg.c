#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* atbeg(struct node* start, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = start;
    return new_node; // New node is now the head of the list
}
struct node*atend(struct node* start, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (start == NULL) {
        return new_node; // List was empty, new node is now the head
    }
    struct node* temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node; // Append at the end
    return start; // Head remains unchanged
}
struct node* atpos(struct node* start, int data, int pos) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    if (pos == 0) {
        new_node->next = start;
        return new_node; // New node is now the head
    }
    struct node* temp = start;
    for (int i = 0; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        free(new_node); // Position is out of bounds
        return start; // No change to the list
    }
    new_node->next = temp->next;
    temp->next = new_node; // Insert at the specified position
    return start; // Head remains unchanged
}
struct node *deleteatbeg(struct node *start) {
    if (start == NULL) {
        return NULL; // List is empty
    }
    struct node* temp = start;
    start = start->next; // Move head to the next node
    free(temp); // Free the old head
    return start; // Return new head
}
struct node *deleteatend(struct node *start) {
    if (start == NULL) {
        return NULL; // List is empty
    }
    if (start->next == NULL) {
        free(start); // Only one node in the list
        return NULL; // List becomes empty
    }
    struct node* temp = start;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next); // Free the last node
    temp->next = NULL; // Update second last node's next to NULL
    return start; // Head remains unchanged
}
struct node *deleteatpos(struct node *start, int pos) {
    if (start == NULL) {
        return NULL; // List is empty
    }
    if (pos == 0) {
        struct node* temp = start;
        start = start->next; // Move head to the next node
        free(temp); // Free the old head
        return start; // Return new head
    }
    struct node* temp = start;
    for (int i = 0; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        return start; // Position is out of bounds, no change to the list
    }
    struct node* node_to_delete = temp->next;
    temp->next = node_to_delete->next; // Bypass the node to be deleted
    free(node_to_delete); // Free the deleted node
    return start; // Head remains unchanged
}