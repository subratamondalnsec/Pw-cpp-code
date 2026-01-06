#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // find the length of original linked list
    ListNode* temp = head;
    int n=0;
    while(temp) {
        temp = temp->next;
        n++;
    }
// breaking the list into k lists
    vector<ListNode*> ans;
    int size = n/k;
    int rem = n%k;
    temp = head;
    while(temp!=NULL) {
        ListNode* c = new ListNode (100);
        ListNode* tempC = c;
        int s = size;
        if(rem>0) s++;
        rem--;
      for(int i=1;i<=s;i++){
        tempC->next = temp;
        temp = temp->next;
        tempC = tempC->next;
       }
        tempC->next = NULL; // V IMP
        ans.push_back(c->next);
}
    if(ans.size()<k) {
        int extra = k - ans.size();
    for(int i=1;i<=extra;i++) {
        ans.push_back(NULL);
        }
    }
    return ans;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& vals) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    for (int val : vals) {
        ListNode* newNode = new ListNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list for testing
    vector<int> vals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ListNode* head = createLinkedList(vals);
    
    // Number of parts to split into
    int k = 3;

    // Create a solution object and call splitListToParts
    Solution solution;
    vector<ListNode*> parts = solution.splitListToParts(head, k);

    // Print the resulting parts
    for (int i = 0; i < parts.size(); i++) {
        cout << "Part " << i + 1 << ": ";
        printLinkedList(parts[i]);
    }

    // Free the allocated memory
    for (ListNode* part : parts) {
        while (part != NULL) {
            ListNode* temp = part;
            part = part->next;
            delete temp;
        }
    }

    return 0;
}