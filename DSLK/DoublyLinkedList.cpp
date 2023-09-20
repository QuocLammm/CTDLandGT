#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;

// Insert a node at the end of the doubly linked list
void insert(int data) {
    // Allocate memory for a new node
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    link->prev = NULL;
    link->next = NULL;

    // If the list is empty, create a new list with a single node
    if (head == NULL) {
        head = link;
        last = link;
        return;
    }

    // Insert the new node at the end of the list
    last->next = link;
    link->prev = last;
    last = link;
}

// Display the doubly linked list
void printList() {
    struct node *ptr = head;
    printf("\n[head] <=>");

    // Traverse the doubly linked list and print each element
    while (ptr != NULL) {
        printf(" %d <=>", ptr->data);
        ptr = ptr->next;
    }

    printf(" [null]\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(1);
    insert(40);
    insert(56);

    printf("Doubly linked list:\n");
    printList();
}
