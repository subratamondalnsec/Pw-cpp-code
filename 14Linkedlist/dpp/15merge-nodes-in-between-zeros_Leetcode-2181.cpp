#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode*t= dummy;
        ListNode* temp= head;
        while(temp){
            if(temp->val==0){
                int sum=0;
                temp=temp->next;
                while( temp && temp->val!=0){
                    sum+=temp->val;
                    temp=temp->next;
                }
                if(sum!=0){
                    ListNode* d=new ListNode(sum);
                    t->next=d;
                    t=t->next;
                }
            }
        }
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;
        int sum = 0;
        while (head) {
            if (head->val == 0) {
                temp->next = new ListNode(sum);
                temp = temp->next;
                sum = 0;
            } else {
                sum += head->val;
            }
            head = head->next;
        }
        return dummy->next->next;
    }
};

// Function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Creating a linked list with nodes: [0,3,1,0,4,5,2,0]
    ListNode* head = new ListNode(0);
    head->next = new ListNode(3);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(0);

    // Solution instance
    Solution sol;
    ListNode* result = sol.mergeNodes(head);

    // Printing the result
    printList(result);

    // Free allocated memory
    ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}