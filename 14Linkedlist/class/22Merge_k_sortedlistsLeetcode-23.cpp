#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*class Solution {//method 1
public:
     ListNode* merge(ListNode* a, ListNode* b) {
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
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return NULL;
        while(arr.size()>1){
            ListNode* a=arr[0];
            arr.erase(arr.begin());
            ListNode* b=arr[0];
            arr.erase(arr.begin());
             ListNode* c=merge(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
};*/
class Solution {//method 2
public:
     ListNode* merge(ListNode* a, ListNode* b) {
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
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return NULL;
        while(arr.size()>1){
            ListNode* a=arr[arr.size()-1];
            arr.pop_back();
            ListNode* b=arr[arr.size()-1];
            arr.pop_back();
             ListNode* c=merge(a,b);
            arr.push_back(c);
        }
        return arr[0];
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

// Main function to test the mergeKLists function
int main() {
    // Creating multiple linked lists
    std::vector<int> list1 = {1, 4, 5};
    std::vector<int> list2 = {1, 3, 4};
    std::vector<int> list3 = {2, 6};
    
    ListNode* a = createLinkedList(list1);
    ListNode* b = createLinkedList(list2);
    ListNode* c = createLinkedList(list3);
    
    std::vector<ListNode*> lists = {a, b, c};
    
    Solution sol;
    ListNode* mergedHead = sol.mergeKLists(lists);
    
    // Print the merged linked list
    printList(mergedHead);
    
    return 0;
}