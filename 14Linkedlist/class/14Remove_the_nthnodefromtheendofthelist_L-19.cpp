#include <bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {//normal method
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp= head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(n==len) {
            head=head->next;
            return head;
        }
        int idx=len-n;//the idx of node to be deleted
        temp=head;
        for(int i=1;i<=idx-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};
class Solution {//interview method
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow= head;
        ListNode* fast= head;
        for(int i=1;i<=n+1;i++){
            if(fast==NULL)return head->next;
            fast=fast->next;
        }
        //move slow and fast at some space
        while(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        //now the slow is exactly at left of the nth node of end
        slow->next= slow->next->next;//delete
        return head;
    }
};
// Function to print the linked list
void display(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating the linked list 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    display(head);

    Solution sol;
    int n = 2;
    head = sol.removeNthFromEnd(head, n);

    cout << "List after removing " << n << "th node from the end: ";
    display(head);

    // Clean up memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}