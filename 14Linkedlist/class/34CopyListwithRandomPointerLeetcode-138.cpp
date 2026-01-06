#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
      // step 1 -> create the deep copy without random pointer

    Node* dummy = new Node(0);
    Node* tempC = dummy;
    Node* temp = head;

    while(temp){
        Node* a = new Node (temp->val);
        tempC->next = a;
        tempC= tempC->next;
        temp = temp->next;
    }
Node* duplicate = dummy->next;

// step 2 -> alternate connections
    Node*a = head;
    Node* b = duplicate;
    dummy= new Node(-1);
    Node* tempD = dummy;
    while(a){
        tempD->next = a;
        a = a->next;
        tempD = tempD->next;
        tempD->next = b;
        b = b->next;
        tempD= tempD->next;
    }
    dummy= dummy->next;

// step 3 -> making atlernate connections

    Node* t1= dummy; // t1 will traverse in the original list
    while(t1){
        Node* t2 = t1->next; // t2 is for duplicate
        if(t1->random) t2->random = t1->random->next; 
        t1= t1->next->next;
    }
// step 4 -> removing the connections (separate)

    Node* d1= new Node(-1);
    Node* d2 = new Node(-1);
    t1= d1;
    Node* t2 = d2;
    Node* t= dummy;
    while(t){
        t1->next = t;
        t = t->next;
        t1= t1->next;
        t2->next = t;
        t = t->next;
        t2 = t2->next;
    }
    t1->next = NULL;
    t2->next = NULL;
    d1=d1->next; // original with random
    d2= d2->next; // duplicate with random
    return d2;  
    }
};

// Helper function to print the list
void printList(Node* head) {
    while (head) {
        cout << "Node value: " << head->val;
        if (head->random)
            cout << ", Random points to: " << head->random->val << endl;
        else
            cout << ", Random points to: nullptr" << endl;
        head = head->next;
    }
}

int main() {
    // Create a sample list
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);

    node1->next = node2;
    node2->next = node3;

    node1->random = node3; // 1's random points to 3
    node2->random = node1; // 2's random points to 1
    node3->random = node2; // 3's random points to 2

    // Print the original list
    cout << "Original list:" << endl;
    printList(node1);

    // Copy the list
    Solution solution;
    Node* copiedList = solution.copyRandomList(node1);

    // Print the copied list
    cout << "Copied list:" << endl;
    printList(copiedList);

    return 0;
}
