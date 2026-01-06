#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {//interviw want
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
class Solution {//normal method
public:
    ListNode* middleNode(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        int mididx=len/2;
        ListNode* mid=head;
        for(int i=1;i<=mididx;i++){
            mid=mid->next;
        }
        return mid;
    }
};

// Function to print the linked list from a given node
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    // Creating the linked list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the original list
    std::cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* middle = sol.middleNode(head);

    // Print the value of the middle node
    std::cout << "Middle node value: " << middle->val << std::endl;

    // Print the list starting from the middle node
    std::cout << "List from middle node: ";
    printList(middle);

    // Clean up memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}