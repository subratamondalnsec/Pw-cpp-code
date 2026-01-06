#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
         ListNode* slow= head;
        ListNode* fast= head;
        bool flag= false;
        while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {
            flag= true; 
            break;
            }
        }
        if(flag== false) return NULL;
        else{
            ListNode* temp= head;
            while(temp!=slow){
                slow=slow->next;
                temp=temp->next;
            }
            return slow; 
        }
    }
};

// Function to create a linked list with a cycle
ListNode* createListWithCycle() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next; // Creating a cycle at node 3
    return head;
}

// Function to clean up memory (assumes no cycle)
void deleteList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Creating a linked list with a cycle
    ListNode* listWithCycle = createListWithCycle();

    Solution sol;
    ListNode* cycleNode = sol.detectCycle(listWithCycle);

    if (cycleNode != NULL) {
        std::cout << "Cycle detected at node with value: " << cycleNode->val << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    // Note: Memory cleanup for listWithCycle is not straightforward due to the cycle.
    // Normally, we should avoid using raw pointers and handle cycles carefully to prevent memory leaks.

    return 0;
}