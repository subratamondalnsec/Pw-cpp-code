#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;
        int carry=0,sum=0;
        while(l1 || l2){
            sum=0;
            if(l1){ 
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){ 
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
           
        }
        if(carry!=0){
            temp->next= new ListNode (carry);
        }
        return dummy->next;
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
    int arr1[] = {2, 4, 3};  // Represents the number 342
    int arr2[] = {5, 6, 4};  // Represents the number 465

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    ListNode* l1 = createList(arr1, size1);
    ListNode* l2 = createList(arr2, size2);

    cout << "List 1: ";
    printList(l1);
    
    cout << "List 2: ";
    printList(l2);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Sum List: ";
    printList(result);

    return 0;
}