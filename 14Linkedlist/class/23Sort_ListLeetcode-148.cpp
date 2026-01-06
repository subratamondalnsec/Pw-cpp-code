#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
     ListNode* merge(ListNode* a, ListNode* b) {
         ListNode* c= new ListNode(100);
         ListNode* temp=c;
         while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
               temp->next=a;
               a = a->next;
               temp=temp->next;
            }
            else{
               temp->next=b;
               b=b->next;
               temp=temp->next;
            }
         }
         if(a==NULL) temp->next=b;
         else temp->next=a;
         return c->next;
    }
    ListNode* sortList(ListNode* head) {
    if(head==NULL||head->next==NULL) return head;//base case
        //to find the left middle  
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //now slow is at left middle
        ListNode* a= head;
        ListNode*b= slow->next;
        slow->next=NULL;
        a=sortList(a);
        b=sortList(b);
        ListNode* c=merge(a,b);
        return c;       
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
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    // Create Solution object
    Solution solution;

    // Sort the list
    ListNode* sortedHead = solution.sortList(head);

    // Print the sorted list
    printList(sortedHead);

    return 0;
}