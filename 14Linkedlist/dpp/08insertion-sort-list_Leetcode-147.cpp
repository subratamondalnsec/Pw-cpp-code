#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr=head,*Next=NULL;
        while(curr){
            Next=curr->next;
            ListNode* temp=dummy;
            while(temp->next && curr->val>temp->next->val){
                temp=temp->next;
            }
            curr->next=temp->next;
            temp->next=curr;
            curr=Next;
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
    int arr[] = {4, 2, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, size);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* sortedHead = solution.insertionSortList(head);

    cout << "Sorted list: ";
    printList(sortedHead);

    return 0;
}