#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        if (!head || !head->next || !head->next->next) return ans;

        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;

        int minDistance = INT_MAX, maxDistance = INT_MIN;
        int firstCritical = -1, lastCritical = -1;
        int n = 1;

        while (c) {
            if ((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)) {
                if (firstCritical == -1) {
                    firstCritical = n;//3
                } else {
                    minDistance = min(minDistance, n - lastCritical);//2 ,1
                }
                lastCritical = n;//3 5 6
                maxDistance = max(maxDistance, lastCritical - firstCritical);//0  3
            }
            a = b;
            b = c;
            c = c->next;
            n++;
        }

        if (firstCritical != lastCritical) {
            ans[0] = minDistance;
            ans[1] = maxDistance;
        }
        return ans;
    }
};

void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a sample linked list: 1 -> 3 -> 2 -> 4 -> 1 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(3);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(5);

    printLinkedList(head);

    Solution sol;
    vector<int> result = sol.nodesBetweenCriticalPoints(head);

    cout << "Minimum distance: " << result[0] << endl;
    cout << "Maximum distance: " << result[1] << endl;

    // Cleaning up the allocated memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}