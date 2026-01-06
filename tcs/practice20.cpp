#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
Node* head = NULL;
void insertAtBeginning(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head) head->prev = newNode;
    head = newNode;
}
void insertAtPosition(int data, int position) {
    if (position == 1) { insertAtBeginning(data); return; }
    Node* newNode = (Node*)malloc(sizeof(Node)), *temp = head;
    newNode->data = data;
    for (int i = 1; temp && i < position - 1; i++) temp = temp->next;
    if (!temp) { printf("Invalid position!\n"); free(newNode); return; }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}
void insertAtEnd(int data) {
    if (!head) { insertAtBeginning(data); return; }
    Node* newNode = (Node*)malloc(sizeof(Node)), *temp = head;
    newNode->data = data;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
}
void deleteAtPosition(int position) {
    if (!head) { printf("List is empty.\n"); return; }
    Node* temp = head;
    if (position == 1) {
        head = head->next;
        if (head) head->prev = NULL;
        free(temp); return;
    }
    for (int i = 1; temp && i < position; i++) temp = temp->next;
    if (!temp) { printf("Invalid position!\n"); return; }
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;
    free(temp);
}

int searchElement(int data) {
    Node* temp = head;
    for (int pos = 1; temp; pos++, temp = temp->next)
        if (temp->data == data) return pos;
    return -1;
}

int countNodes() {
    int count = 0;
    for (Node* temp = head; temp; temp = temp->next) count++;
    return count;
}

void sortList() {
    for (Node* i = head; i && i->next; i = i->next){
        for (Node* j = i->next; j; j = j->next){
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
    }   }   }
}

void displayList() {
    if (!head) { printf("List is empty.\n"); return; }
    printf("Doubly Linked List: ");
    for (Node* temp = head; temp; temp = temp->next) printf("%d ", temp->data);
    printf("\n");
}

int main() {
    int choice, data, position;
    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at beginning\n2. Insert at position\n3. Insert at end\n");
        printf("4. Delete at position\n5. Search element\n6. Count nodes\n");
        printf("7. Sort list\n8. Display list\n9. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter data: "); scanf("%d", &data); insertAtBeginning(data); break;
            case 2: printf("Enter data: "); scanf("%d", &data);
                    printf("Enter position: "); scanf("%d", &position); insertAtPosition(data, position); break;
            case 3: printf("Enter data: "); scanf("%d", &data); insertAtEnd(data); break;
            case 4: printf("Enter position: "); scanf("%d", &position); deleteAtPosition(position); break;
            case 5: printf("Enter data to search: "); scanf("%d", &data);
                    position = searchElement(data);
                    printf(position != -1 ? "Found at position: %d\n" : "Not found\n", position); break;
            case 6: printf("Node count: %d\n", countNodes()); break;
            case 7: sortList(); printf("List sorted.\n"); break;
            case 8: displayList(); break;
            case 9: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
