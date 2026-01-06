#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        while (head != NULL) {
            if (head->next and head->val == head->next->val) {
                while (head->next && head->val == head->next->val)    head = head->next;

                temp->next = head->next;
            } 
            else  temp = temp->next;

            head = head->next;
        }
        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example usage
    int arr[] = {1, 2, 3, 3, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, size);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* newHead = solution.deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(newHead);

    return 0;
}