#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* head = NULL;
void insertAtBeginning(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}
void insertAtPosition(int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(data);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp->next == head) {
            printf("Position out of bounds!\n");
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void insertAtEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
}
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (position == 1) {
        Node* temp = head;
        Node* last = head;
        while (last->next != head)
            last = last->next;
        if (head->next == head) {
            head = NULL;
        } else {
            head = head->next;
            last->next = head;
        }
        free(temp);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp->next == head) {
            printf("Position out of bounds!\n");
            return;
        }
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}
int searchElement(int data) {
    if (head == NULL)
        return -1;
    Node* temp = head;
    int position = 1;
    do {
        if (temp->data == data)
            return position;
        temp = temp->next;
        position++;
    } while (temp != head);
    return -1;
}
int countNodes() {
    if (head == NULL)
        return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
void sortList() {
    if (head == NULL)
        return;
    Node* current = head;
    Node* index = NULL;
    int temp;
    do {
        index = current->next;
        while (index != head) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    } while (current->next != head);
}
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, data, position;
    while (1) {
        printf("\nCircular Linked List Operations:\n1. Insert at beginning\n2. Insert at specified position\n");
        printf("3. Insert at end\n4. Delete an element from a specified position\n5. Search an element\n");
        printf("6. Count number of nodes\n7. Sort the entire list\n8. Display the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 5:
                printf("Enter data to search: ");
                scanf("%d", &data);
                position = searchElement(data);
                if (position != -1)
                    printf("Element found at position: %d\n", position);
                else
                    printf("Element not found.\n");
                break;
            case 6:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 7:
                sortList();
                printf("List sorted.\n");
                break;
            case 8:
                displayList();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
