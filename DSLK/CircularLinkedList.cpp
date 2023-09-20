#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

// Insert a node at the end of the circular linked list
void insert(int data) {
    // Allocate memory for a new node
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;

    // If the list is empty, create a new list with a single node
    if (head == NULL) {
        head = link;
        head->next = link;
        return;
    }

    current = head;

    // Traverse to the end of the list
    while (current->next != head)
        current = current->next;

    // Insert the new node at the end of the list
    current->next = link;

    // Link the last node to the head
    link->next = head;
}

// Display the circular linked list
void printList() {
    struct node *ptr = head;
    printf("\n[head] =>");

    // Traverse the circular list and print each element
    while (ptr->next != head) {
        printf(" %d =>", ptr->data);
        ptr = ptr->next;
    }

    printf(" %d =>", ptr->data);
    printf(" [head]\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(1);
    insert(40);
    insert(56);

    printf("Circular linked list:\n");
    printList();

    return 0;
}
