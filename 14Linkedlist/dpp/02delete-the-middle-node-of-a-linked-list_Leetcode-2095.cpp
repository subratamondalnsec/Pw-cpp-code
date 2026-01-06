#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast= head;
        if(fast->next==NULL) return head->next;
        if(fast->next->next==NULL){
            fast->next=NULL;
            return head;
        }
        fast=fast->next->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
void printList(ListNode* head) {
    while (head != NULL) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    std::cout << "Original List: ";
    printList(head);
    
    Solution solution;
    head = solution.deleteMiddle(head);
    
    std::cout << "List after deleting the middle node: ";
    printList(head);
    
    // Free allocated memory (optional)
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}