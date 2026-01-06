#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp= head;
        k--;
        while(k--) temp=temp->next;
        ListNode* slow= head;
        ListNode* fast= temp->next;
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        swap(temp->val,slow->val);
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
    int k = 2;
    head = solution.swapNodes(head, k);

    std::cout << "List after swapping the " << k << "-th node from start and end: ";
    printList(head);

    // Free allocated memory (optional)
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}