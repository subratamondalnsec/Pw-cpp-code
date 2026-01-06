#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Insert (Enqueue) operation
void enqueue() {
    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Heap overflow! Unable to allocate memory.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d inserted into the queue.\n", data);
}

// Delete (Dequeue) operation
void dequeue() {
    if (front == NULL) {
        printf("Queue underflow! The queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    printf("Dequeued element: %d\n", temp->data);
    free(temp);
}

// Display operation
void display() {
    if (front == NULL) {
        printf("The queue is empty.\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nQueue Operations using Linked List:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            enqueue();
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            exit(0);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
