#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true; 
        }
        return false;
    }
};
// Function to create a linked list without a cycle
ListNode* createListWithoutCycle() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    return head;
}

// Function to create a linked list with a cycle
ListNode* createListWithCycle() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next; // Creating a cycle
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
    // Creating a linked list without a cycle
    ListNode* listWithoutCycle = createListWithoutCycle();
    Solution sol;

    std::cout << "Testing list without cycle: " 
              << (sol.hasCycle(listWithoutCycle) ? "Cycle detected" : "No cycle detected") 
              << std::endl;

    // Creating a linked list with a cycle
    ListNode* listWithCycle = createListWithCycle();

    std::cout << "Testing list with cycle: " 
              << (sol.hasCycle(listWithCycle) ? "Cycle detected" : "No cycle detected") 
              << std::endl;

    // Clean up memory for the list without cycle
    deleteList(listWithoutCycle);
    // Note: Memory cleanup for listWithCycle is not straightforward due to the cycle.
    // Normally, we should avoid using raw pointers and handle cycles carefully to prevent memory leaks.

    return 0;
}

