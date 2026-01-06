#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*class Solution {//method 1
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* tempA= a;
        ListNode* tempB= b;
        ListNode* c= new ListNode(100);
         ListNode* tempC=c;
         while(tempA!=NULL&&tempB!=NULL){
            if(tempA->val<=tempB->val){
               ListNode* t= new ListNode(tempA->val); 
               tempC->next=t;
               tempC=t;
               tempA=tempA->next;
            }
            else{
                ListNode* t= new ListNode(tempB->val); 
               tempC->next=t;
               tempC=t;
               tempB=tempB->next;
            }
         }
         if(tempA==NULL){
            tempC->next=tempB;
         }
         else{
             tempC->next=tempA;
         }
         return c->next;
    }
};*/

class Solution {//method 2
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
         ListNode* c= new ListNode(100);
         ListNode* temp=c;
         while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
               temp->next=a;
               a = a->next;
               temp=temp->next;
            }
            else{
               temp->next=b;
               b=b->next;
               temp=temp->next;
            }
         }
         if(a==NULL) temp->next=b;
         else temp->next=a;
         return c->next;
    }
};
// Function to create a linked list from a vector
ListNode* createLinkedList(const std::vector<int>& values) {
    if (values.empty()) return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Function to print the linked list
void printList(ListNode* node) {
    while (node != NULL) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

// Main function to test the mergeTwoLists function
int main() {
    std::vector<int> list1 = {1, 2, 4};
    std::vector<int> list2 = {1, 3, 4};
    
    ListNode* a = createLinkedList(list1);
    ListNode* b = createLinkedList(list2);
    
    Solution sol;
    ListNode* mergedHead = sol.mergeTwoLists(a, b);
    
    // Print the merged linked list
    printList(mergedHead);
    
    return 0;
}