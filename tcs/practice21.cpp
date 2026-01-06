#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* top = NULL;
void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap overflow! Unable to allocate memory.\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}
void pop() {
    if (!top) {
        printf("Stack underflow! The stack is empty.\n");
        return;
    }
    Node* temp = top;
    top = top->next;
    printf("Popped %d from the stack.\n", temp->data);
    free(temp);
}
void display() {
    if (!top) {
        printf("The stack is empty.\n");
        return;
    }
    Node* temp = top;
    printf("Stack elements (from top to bottom): ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nStack Operations using Linked List:\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}