#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {//method 1
public:
    int len=0;
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *curr = head, *Next = head;
        while(curr) {
            len++;
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head=reverseList(head);
        stack<int>st;
        st.push(head->val);
        vector<int>ans(len,0);
        int i=0;
        while(head){
            while(st.size()>0 && head->val>=st.top()) st.pop();
            if(st.size()!=0) ans[i]=st.top();
            st.push(head->val);
            head=head->next;
            i++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

class Solution {//method 2
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        ListNode*temp= head;
        while(temp){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int n=v.size();
        stack<int>st;
        vector<int>ans(n,0);
        st.push(v[n-1]);
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 && st.top() <= v[i]) st.pop();
            if(st.size()==0) ans[i]=0;
            else ans[i]=st.top();
            st.push(v[i]);
        }
        return ans;
    }
};

// Helper function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (int i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function for testing
int main() {
    // Test case
    vector<int> values = {2, 7, 4, 3, 5};  // Example linked list values
    ListNode* head = createLinkedList(values);  // Create linked list from values

    Solution solution;
    vector<int> result = solution.nextLargerNodes(head);  // Find the next larger nodes

    // Print the result
    cout << "Next larger nodes: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}