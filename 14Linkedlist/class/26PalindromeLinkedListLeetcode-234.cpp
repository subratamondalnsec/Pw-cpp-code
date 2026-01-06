#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*class Solution {//m1
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
    bool isPalindrome(ListNode* head) {
        ListNode* c=new ListNode(10);
        //deep copy of head
        ListNode* temp=head;
        ListNode* tempC=c;
        while(temp){//Tc=O(n)  && sc=O(n)
            ListNode* node =new ListNode(temp->val);
            tempC->next=node;
            temp=temp->next;
            tempC=tempC->next;
        }
        c=c->next;
        c=reverseList(c);//Tc=O(n)
        ListNode* a= head;
        ListNode* b=c;
        while(a){//Tc=O(n)
            if(a->val !=b->val) return false;
            a=a->next;
            b=b->next;          
        }
        return true;
    }
};*/
class Solution {//m2
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
    bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL) {
        slow= slow->next;
        fast= fast->next->next;
    }
        // slow is at the left middle / middle
        ListNode* newHead= reverseList(slow->next);
        ListNode* a = head;
        ListNode* b = newHead;
    while(b) {
        if (a->val != b->val) return false;
        a = a->next;
        b=b->next;
    }
        return true;
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
    // Create a test case for isPalindrome
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    printList(head);
    // Create Solution object
    Solution solution;

    // Check if the list is a palindrome
    bool result = solution.isPalindrome(head);

    // Print the result
    cout << "Is the list a palindrome? :=>" << (result ? "Yes" : "No") << endl;

    // Free the allocated memory for the original list
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}