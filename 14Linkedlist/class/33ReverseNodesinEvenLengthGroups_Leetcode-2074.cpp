#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode *prev = NULL, *curr = head, *Next = head;
    while(curr) {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if(left== right) return head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* c = NULL;
        ListNode* d = NULL;
        ListNode* temp = head;
        int n = 1;
    while(temp) {
        if(n==left-1) a = temp;
        if(n==left) b = temp;
        if(n==right) c = temp;
        if(n==right+1) d = temp;
        temp = temp->next;
        n++;
    }
        if(a) a->next = NULL;
        c->next = NULL;
        c= reverseList(b);
        if(a) a->next = c;
        b->next = d;
        if(a) return head;
        return c;  
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
       ListNode* temp=head;
        int gap=1;
        while(temp && temp->next){
            int remlen=0;
            ListNode* t= temp->next;
            for(int i=1;i<=gap+1 && t!=NULL;i++){
                t=t->next;
                remlen++;
            }
            if(remlen<gap+1) gap=remlen-1;
            if(gap%2!=0) reverseBetween(temp, 2,2+gap);
            gap++;
            for(int i=1;temp !=NULL&&i<=gap;i++){
              temp= temp->next;
            }
            
        }
        return head;
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
    // Create a test case
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    printLinkedList(head);
    // Create Solution object
    Solution solution;

    // Reverse between position 2 and 4
    ListNode* modifiedHead = solution.reverseEvenLengthGroups(head);

    // Print the modified list
    printLinkedList(modifiedHead);

    // Free the allocated memory
    while (modifiedHead != NULL) {
        ListNode* temp = modifiedHead;
        modifiedHead = modifiedHead->next;
        delete temp;
    }

    return 0;
}
