#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *even = NULL;
struct node *odd = NULL;
struct node *list = NULL;

void insert(int data) {
    // Allocate memory for a new node
    struct node *link = (struct node *)malloc(sizeof(struct node));
    struct node *current;

    link->data = data;
    link->next = NULL;

    if (list == NULL) {
        list = link;
        return;
    }

    current = list;

    while (current->next != NULL)
        current = current->next;

    current->next = link;
}

void display(struct node *head) {
    struct node *ptr = head;
    printf("[head] =>");

    while (ptr != NULL) {
        printf(" %d =>", ptr->data);
        ptr = ptr->next;
    }

    printf(" [null]\n");
}

void split_list() {
    struct node *current;
    
    while (list != NULL) {
        struct node *link = (struct node *)malloc(sizeof(struct node));

        link->data = list->data;
        link->next = NULL;

        if (list->data % 2 == 0) {
            if (even == NULL) {
                even = link;
            } else {
                current = even;

                while (current->next != NULL)
                    current = current->next;

                current->next = link;
            }
        } else {
            if (odd == NULL) {
                odd = link;
            } else {
                current = odd;

                while (current->next != NULL)
                    current = current->next;

                current->next = link;
            }
        }
        list = list->next;
    }
}

int main() {
    int i;

    for (i = 1; i <= 10; i++)
        insert(i);

    printf("Danh sach ban dau: \n");
    display(list);

    split_list();

    printf("\nDanh sach le: ");
    display(odd);
    printf("\nDanh sach chan: ");
    display(even);
}
