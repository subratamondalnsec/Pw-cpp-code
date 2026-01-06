#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n=0;
        ListNode* temp= head;
        while(temp){
            n++;
            temp=temp->next;
        }
        int x=pow(2,n-1);
        temp= head;
        int sum=0;
        while(temp){
            sum+=(temp->val*x);
            temp=temp->next;
            x/=2;
        }
        return sum;
    }
};

// Helper function to print the linked list (for visualization purposes)
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
    int binaryArr[] = {1, 0, 1};  // Represents the binary number 101 (which is 5 in decimal)
    int size = sizeof(binaryArr) / sizeof(binaryArr[0]);

    ListNode* head = createList(binaryArr, size);

    cout << "Binary linked list: ";
    printList(head);

    Solution solution;
    int decimalValue = solution.getDecimalValue(head);

    cout << "Decimal value: " << decimalValue << endl;

    return 0;
}