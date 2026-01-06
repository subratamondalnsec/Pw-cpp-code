#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd=new ListNode(100);
        ListNode* even=new ListNode(234);
        ListNode* to=odd;
        ListNode* te=even;
        ListNode* t =head;
        int n=1;
        while(t!=NULL){
            if(n%2==1){
                to->next=t;
                t=t->next;
                to=to->next;
            }
            else{
                te->next=t;
                t=t->next;
                te=te->next;
            }
            n++;
        }
        to->next=even->next;
        te->next=NULL;
        return odd->next;
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL ||head->next==NULL || head->next->next==NULL) return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* te=even;
        while(te && te->next){
            odd->next=te->next;
            odd=odd->next;
            te->next=odd->next;
            te=te->next;
        }
        odd->next=even;
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example usage
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, size);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* modifiedHead = solution.oddEvenList(head);

    cout << "Modified list (Odd followed by Even): ";
    printList(modifiedHead);

    return 0;
}