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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow= slow->next;
            fast= fast->next->next;
        }
            // slow is at the left middle / middle
        ListNode* newHead= reverseList(slow->next);
        ListNode* a = head;
        ListNode* b = newHead;
        int mx=INT_MIN;
        while(a && b){
            int sum=a->val+b->val;
            mx=max(mx,sum);
            a = a->next;
            b=b->next;
        }
        return mx;
    }
};

// Function to create a linked list from an array of values
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Main function
int main() {
    // Example input
    vector<int> values = {1, 2, 3, 4, 5, 6};
    
    // Create linked list
    ListNode* head = createLinkedList(values);

    // Create Solution object
    Solution solution;

    // Calculate and print the result
    int result = solution.pairSum(head);
    cout << "Maximum pair sum: " << result << endl;

    // Clean up the linked list memory (optional for larger linked lists)
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}