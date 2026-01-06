#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lo=new ListNode(100);
        ListNode* hi=new ListNode(234);
        ListNode* th=hi;
        ListNode* tl=lo;
        ListNode* t =head;
        while(t!=NULL){
            if(t->val<x){
                tl->next=t;
                t=t->next;
                tl=tl->next;
            }
            else{
                th->next=t;
                t=t->next;
                th=th->next;
            }
        }
        tl->next=hi->next;
        th->next=NULL;
        return lo->next;
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
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

     printList(head);
    // Create Solution object
    Solution solution;

    // Partition the list
    ListNode* partitionedHead = solution.partition(head, 3);

    // Print the partitioned list
    printList(partitionedHead);

    // Free the allocated memory
    while (partitionedHead != NULL) {
        ListNode* temp = partitionedHead;
        partitionedHead = partitionedHead->next;
        delete temp;
    }

    return 0;
}