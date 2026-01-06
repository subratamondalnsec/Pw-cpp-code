#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        int n=0;
        ListNode* temp= head;
        ListNode* tail=NULL; 
        while(temp!=NULL){
            if(temp->next==NULL) tail=temp;
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0) return head;
        temp=head;
        for(int i=1;i<(n-k);i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};
// Function to print the linked list
void printList(ListNode* node) {
    while (node != NULL) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Main function to test the rotateRight function
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    int k = 2;  // Number of rotations
    
    Solution sol;
    head = sol.rotateRight(head, k);
    
    // Print the rotated list
    printList(head);
    
    return 0;
}