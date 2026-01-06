#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*class Solution {//m1 normal and bekar method
public:
    ListNode* getNodeAt(ListNode* head, int idx) {
    ListNode* temp = head;
// 1 2 3 4 5
    for(int i=1;i<=idx;i++) {
    temp = temp->next;
}
return temp;
}
    ListNode* reverseList(ListNode* head) {
int n = 0;
ListNode* temp = head;
    while(temp){
        cout<<temp->val;
        temp = temp->next;
        n++;
    }
    int i = 0;
    int j = n-1;
    while(i<j){
        ListNode* left = getNodeAt(head, i);
        ListNode* right = getNodeAt(head,j);
        int t = left->val;
        left->val = right->val;
        right->val = t;
        i++;
        j--;
    }
    temp = head;
    while(temp) {
        temp = temp->next;
    }
    return head;
    }
};*/
/*class Solution {//m2 three pointer method
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
};*/
class Solution {//m3 recursive method
public:
    ListNode* reverseList(ListNode* head) {
        if (head== NULL || head->next==NULL) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
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

    printList(head);
    // Create Solution object
    Solution solution;

    // Reverse the list
    ListNode* reversedHead = solution.reverseList(head);

    // Print the reversed list
    printList(reversedHead);

    // Free the allocated memory
    while (reversedHead != NULL) {
        ListNode* temp = reversedHead;
        reversedHead = reversedHead->next;
        delete temp;
    }
    return 0;
}