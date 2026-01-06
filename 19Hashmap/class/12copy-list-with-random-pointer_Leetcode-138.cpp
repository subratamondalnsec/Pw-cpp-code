#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {//t.c=O(n),s.c=O(n)
        Node* temp = head;
        Node* dummy = new Node(0);
        Node* t = dummy;

        // Step 1: Create a new linked list with the same values
        while (temp) {
            t->next = new Node(temp->val);
            t = t->next;
            temp = temp->next;
        }

        // Step 2: Map original nodes to the corresponding new nodes
        unordered_map<Node*, Node*> m;
        Node* a = head;
        Node* b = dummy->next;
        Node* tempb = b;
        while (a != NULL) {
            m[a] = tempb;
            a = a->next;
            tempb = tempb->next;
        }

        // Step 3: Set random pointers for the new nodes
        for (auto x : m) {
            Node* o = x.first;  // original node
            Node* d = x.second; // deep copied node
            if (o->random != NULL)
                d->random = m[o->random];
        }
        
        return b;
    }
};

// Helper function to print the linked list with random pointers
void printList(Node* head) {
    while (head) {
        cout << "Node value: " << head->val;
        if (head->random)
            cout << ", Random points to: " << head->random->val;
        else
            cout << ", Random points to: nullptr";
        cout << endl;
        head = head->next;
    }
}

int main() {
    // Creating an example list: 1 -> 2 -> 3 with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    // Set random pointers
    head->random = head->next->next;  // 1's random points to 3
    head->next->random = head;        // 2's random points to 1
    head->next->next->random = head->next; // 3's random points to 2

    // Debug log: Print original list
    cout << "Original list:\n";
    printList(head);

    // Use Solution to copy the list
    Solution sol;
    Node* copiedList = sol.copyRandomList(head);

    // Debug log: Print copied list
    cout << "\nCopied list:\n";
    printList(copiedList);

    return 0;
}
