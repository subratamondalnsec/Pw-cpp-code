#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};
class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp= head;
        while(temp!=NULL){
            Node*a =temp-> next;
            if(temp->child != NULL){
                Node*c =temp-> child;
                temp->child=NULL;//v IMP
                c=flatten(c);//recursion
                temp->next=c;
                c->prev=temp;
                while(c->next!=NULL ){
                    c=c->next;
                }
                c->next=a;
               if(a) a->prev=c;//error
            }
            temp=a;
        }
        return head;
    }
};

// Helper function to print the flattened list
void printList(Node* head) {
    while (head) {
        std::cout << "Value: " << head->val<<endl;
        head = head->next;
    }
    cout <<endl;
}

// Helper function to create a multilevel doubly linked list
Node* createList(const vector<vector<int>>& listValues) {
    if (listValues.empty()) return nullptr;

    vector<Node*> nodes;
    for (const auto& level : listValues) {
        Node* head = nullptr;
        Node* prev = nullptr;
        for (int val : level) {
            Node* newNode = new Node(val);
            if (!head) head = newNode;
            if (prev) {
                prev->next = newNode;
                newNode->prev = prev;
            }
            prev = newNode;
        }
        nodes.push_back(head);
    }

    for (size_t i = 1; i < nodes.size(); ++i) {
        if (nodes[i - 1]) {
            Node* temp = nodes[i - 1];
            while (temp->next) temp = temp->next;
            temp->child = nodes[i];
        }
    }

    return nodes[0];
}

// Main function
int main() {
    // Create a sample multilevel doubly linked list
    std::vector<std::vector<int>> listValues = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10},
        {11, 12}
    };

    Node* head = createList(listValues);

    // Creating a solution object
    Solution sol;
    Node* flattenedList = sol.flatten(head);

    // Printing the flattened list
    cout << "Flattened list:" << endl;
    printList(flattenedList);

    return 0;
}
