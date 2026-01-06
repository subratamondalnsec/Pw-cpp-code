#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Comparator struct to define custom ordering for priority queue
struct comparator {
    bool operator()(ListNode* l, ListNode* r) {
        return l->val > r->val;  // Min-heap, so we want the smallest value at the top
    }
};

class Solution {
public:
    // Function to merge k sorted linked lists using a priority queue (min-heap)
    ListNode* mergeKLists(vector<ListNode*>& v) {
        priority_queue<ListNode*, vector<ListNode*>, comparator> pq;

        // Push the head of each linked list into the priority queue
        for (int i = 0; i < v.size(); i++) {
            if (v[i]) pq.push(v[i]);
        }

        ListNode* head = nullptr;  // Start of the merged linked list
        ListNode* tail = nullptr;  // End of the merged linked list

        // Extract nodes from the priority queue and build the merged list
        while (!pq.empty()) {
            auto temp = pq.top();  // Get the node with the smallest value
            pq.pop();

            // If there's a next node in the same list, push it into the queue
            if (temp->next) pq.push(temp->next);

            // If this is the first node, initialize head and tail
            if (!head) {
                head = tail = temp;
            } else {
                // Otherwise, append the node to the result and update tail
                tail->next = temp;
                tail = tail->next;
            }
        }

        return head;  // Return the merged linked list
    }
};

// Utility function to create a linked list from a vector of integers
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

// Utility function to print the linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the mergeKLists function
int main() {
    // Create k sorted linked lists
    vector<ListNode*> lists;
    
    vector<int> l1 = {1, 4, 5};
    vector<int> l2 = {1, 3, 4};
    vector<int> l3 = {2, 6};

    lists.push_back(createLinkedList(l1));
    lists.push_back(createLinkedList(l2));
    lists.push_back(createLinkedList(l3));

    // Create a Solution object and merge the lists
    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    // Print the merged linked list
    printLinkedList(result);

    return 0;
}
