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
        if(head==NULL||head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL){
            while(fast!=NULL && slow->val==fast->val) fast=fast->next;
                slow->next=fast;
                slow=fast;
             if(fast!=NULL)   fast=fast->next;
        }
        return head;
    }
};

// Function to print the linked list
void printList(ListNode* node) {
    while (node != NULL) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Main function to test the deleteDuplicates function
int main() {
    // Creating a sorted linked list: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    printList(head);
    Solution sol;
    head = sol.deleteDuplicates(head);
    
    // Print the updated list
    printList(head);
    
    return 0;
}