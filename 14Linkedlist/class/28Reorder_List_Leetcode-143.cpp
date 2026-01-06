#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *curr = head, *Next = head;
    while(curr) {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL) {
        slow = slow->next;
        fast= fast->next->next;
    }
// slow is at the left middle / middle
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow->next = NULL; // for breaking the lists
        // merge these two - a and b alternatively
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        ListNode* tempA = a;
        ListNode* tempB = b;
    while(tempA && tempB) {
        tempC->next = tempA;
        tempA= tempA->next;
        tempC = tempC->next;
        tempC->next = tempB;
        tempB = tempB->next;
        tempC = tempC->next;
    }
        tempC->next = tempA;
        head= c->next;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a test case
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    printList(head);
    // Create Solution object
    Solution solution;

    // Reorder the list
    solution.reorderList(head);

    // Print the reordered list
    printList(head);

    // Free the allocated memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}