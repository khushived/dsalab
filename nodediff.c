#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
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

// Function to find the difference between two node values
int findNodeDifference(struct Node* head, int value1, int value2) {
    struct Node* current = head;
    int found1 = 0, found2 = 0;
    int nodeValue1 = 0, nodeValue2 = 0;

    // Traverse the linked list
    while (current != NULL) {
        if (current->data == value1) {
            found1 = 1;
            nodeValue1 = current->data;
        } else if (current->data == value2) {
            found2 = 1;
            nodeValue2 = current->data;
        }
        current = current->next;
    }

    // If one of the values is not found, return -1
    if (!found1 || !found2) {
        return -1;
    }

    // Return the absolute difference between the node values
    return abs(nodeValue1 - nodeValue2);
}

// Main function
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(3);
    head->next->next = createNode(5);
    head->next->next->next = createNode(7);
    head->next->next->next->next = createNode(9);

    int value1 = 3;
    int value2 = 7;

    int difference = findNodeDifference(head, value1, value2);

    if (difference != -1) {
        printf("Difference between %d and %d: %d\n", value1, value2, difference);
    } else {
        printf("One or both values not found in the linked list.\n");
    }

    // Free memory
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
