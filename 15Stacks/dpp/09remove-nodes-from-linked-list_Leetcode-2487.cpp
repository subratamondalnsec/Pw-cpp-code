#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;
        while (head) {
            st.push(head);
            head = head->next;
        }
        ListNode* tail = st.top();
        st.pop();
        int mx = tail->val;
        while (!st.empty()) {
            ListNode* top = st.top();
            st.pop();
            if (top->val >= mx) {
                top->next = tail;
                tail = top;
                mx = top->val;
            }
        }
        return tail; 
    }
};

// Assuming ListNode is already defined as given above

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Construct a linked list: 5 -> 2 -> 13 -> 3 -> 8
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);

    // Call the removeNodes function and get the new head
    ListNode* newHead = solution.removeNodes(head);

    // Output the modified linked list
    cout << "Modified linked list: ";
    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}