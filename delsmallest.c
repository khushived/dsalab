#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the linked list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Function to delete the node with the smallest value in the list
void deleteSmallest(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *current = *head, *prev = NULL;
    int smallest = INT_MAX;

    // Find the smallest value in the list
    while (current != NULL) {
        if (current->data < smallest) {
            smallest = current->data;
        }
        current = current->next;
    }

    // Find the node with the smallest value and delete it
    current = *head;
    while (current != NULL && current->data != smallest) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Smallest element not found.\n");
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Function to display the linked list
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* myList = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Add element to the list\n");
        printf("2. Display the list\n");
        printf("3. Delete smallest element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &data);
                append(&myList, data);
                break;
            case 2:
                printf("Linked List: ");
                display(myList);
                break;
            case 3:
                deleteSmallest(&myList);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}