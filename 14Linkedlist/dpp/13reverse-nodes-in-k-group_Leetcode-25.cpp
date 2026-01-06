#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int len = 0;
        while (temp) {
            len++;
            temp = temp->next;
        }
        if(!head || len<k) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* curr=dummy;
        ListNode* nex=dummy;
        while(len>=k){
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
            }
            prev=curr;
            len-=k;
        }
        return dummy->next;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Example usage
    int arr[] = {1, 2, 3, 4, 5};
    int k = 3;
    ListNode* head = createLinkedList(arr, 5);

    cout << "Original List: ";
    printLinkedList(head);

    head = solution.reverseKGroup(head, k);

    cout << "Reversed in K-Groups List: ";
    printLinkedList(head);

    return 0;
}