#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* slow= list1;
        ListNode* fast= list1;
        ListNode* temp= list2;
        for(int i=1;i<a;i++){
            slow=slow->next;
        }
        for(int i=1;i<=b+1;i++){
            fast=fast->next;
        }
        while(temp->next!=NULL) temp=temp->next;
        slow->next=list2;
        temp->next=fast;
        return list1;
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
    // Creating list1: 0 -> 1 -> 2 -> 3 -> 4 -> 5
    ListNode* list1 = new ListNode(0);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(4);
    list1->next->next->next->next->next = new ListNode(5);

    // Creating list2: 1000000 -> 1000001 -> 1000002
    ListNode* list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    std::cout << "Original List 1: ";
    printList(list1);

    std::cout << "Original List 2: ";
    printList(list2);

    Solution solution;
    list1 = solution.mergeInBetween(list1, 3, 4, list2); // Merge list2 into list1 between positions 3 and 4

    std::cout << "Modified List 1 after merging: ";
    printList(list1);

    // Free allocated memory (optional)
    while (list1 != NULL) {
        ListNode* temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2 != NULL) {
        ListNode* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}