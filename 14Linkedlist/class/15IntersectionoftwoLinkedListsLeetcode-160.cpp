#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
ListNode* tempB = headB;
int lenA=0;
while(tempA!=NULL){
    lenA++;
    tempA=tempA->next;
}
int lenB=0;
while(tempB!=NULL){
    lenB++;
    tempB=tempB->next;
}
tempA=headA;
tempB=headB;
for(int i=abs(lenA-lenB);i>0;i--){
    if(lenA>lenB) tempA=tempA->next;
    else if(lenA<lenB) tempB=tempB->next;
}
while(tempA!=tempB){
    tempA = tempA->next;
    tempB = tempB->next;
}
return tempA;
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
    // Creating two intersecting linked lists
    // List A: 1->2->3->4->5->6
    // List B:      9->5->6
    ListNode* intersect = new ListNode(5);
    intersect->next = new ListNode(6);
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = intersect;

    ListNode* headB = new ListNode(9);
    headB->next = intersect;
    printList(headA);
    printList(headB);

    Solution sol;
    ListNode* intersectionNode = sol.getIntersectionNode(headA, headB);

    if (intersectionNode != NULL) {
        std::cout << "Intersection at node with value: " << intersectionNode->val << std::endl;
    } else {
        std::cout << "No intersection." << std::endl;
    }
    // Clean up memory
    ListNode* temp;
    while (headA != intersect) {
        temp = headA;
        headA = headA->next;
        delete temp;
    }
    while (headB != intersect) {
        temp = headB;
        headB = headB->next;
        delete temp;
    }
    delete intersect->next; // Deleting 6
    delete intersect;       // Deleting 5

    return 0;
}