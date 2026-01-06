#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        // Initialize pointers
        ListNode* newHead = head->next; // After the first swap, this will be the new head
        ListNode* prev = NULL; // To keep track of the previous node
        ListNode* curr = head; // Start with the first node

        while (curr != NULL && curr->next != NULL) {
            ListNode* nextPair = curr->next->next; // Save the next pair of nodes
            ListNode* second = curr->next; // The second node in the pair

            // Swap the current pair
            second->next = curr;
            curr->next = nextPair;

            // Update the previous pair's link
            if (prev != NULL) {
                prev->next = second;
            }

            // Move pointers forward
            prev = curr;
            curr = nextPair;
        }

        return newHead; // Return the new head after swaps
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        int len=0,k=2;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prev=dummy;
        ListNode*curr,*nex;
        while(len>=k){
            curr=prev->next;
            nex=curr->next;
            curr->next=nex->next;
            nex->next=prev->next;
            prev->next=nex;
            nex=curr->next;
            prev=curr;
            len-=k;
        }
        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    // Example: Creating a linked list [1, 2, 3, 4]
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, size);

    // Swap pairs
    ListNode* result = solution.swapPairs(head);

    // Print the result
    printList(result);

    return 0;
}
