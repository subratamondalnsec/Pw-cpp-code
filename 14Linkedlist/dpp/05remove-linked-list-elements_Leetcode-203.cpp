#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val){
            head=head->next;
        }
        if (head == NULL) return NULL;
        ListNode* slow= head;
        ListNode* fast= head->next;
        while(fast!=NULL){
            if(fast->val==val)  slow->next=fast->next;
            else   slow=fast;

            fast=fast->next;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val){
            head=head->next;
        }
        if (head == NULL) return NULL;
        ListNode* slow= head;
        while(slow!=NULL){
            if(slow->next!=NULL && slow->next->val==val)  slow->next=slow->next->next;
            else   slow=slow->next;
        }
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
    // Creating a linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    std::cout << "Original List: ";
    printList(head);

    Solution solution;
    int val = 6;
    head = solution.removeElements(head, val);

    std::cout << "List after removing elements with value " << val << ": ";
    printList(head);

    // Free allocated memory (optional)
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}