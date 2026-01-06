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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if(left== right) return head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        int n = 1;
    while(temp) {
        if(n==left-1) a = temp;
        if(n==left) b = temp;
        if(n==right) c = temp;
        if(n==right+1) d = temp;
        temp = temp->next;
        n++;
    }
        if(a) a->next = NULL;
        c->next = NULL;
        c= reverseList(b);
        if(a) a->next = c;
        b->next = d;
        if(a) return head;
        return c;  
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
     head->next->next->next->next->next = new ListNode(6);
      head->next->next->next->next->next->next = new ListNode(7);

    printList(head);
    // Create Solution object
    Solution solution;

    // Reverse between position 2 and 4
    ListNode* modifiedHead = solution.reverseBetween(head, 4, 6);

    // Print the modified list
    printList(modifiedHead);

    // Free the allocated memory
    while (modifiedHead != NULL) {
        ListNode* temp = modifiedHead;
        modifiedHead = modifiedHead->next;
        delete temp;
    }

    return 0;
}
