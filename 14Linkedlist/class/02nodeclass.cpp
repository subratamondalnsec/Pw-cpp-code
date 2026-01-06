#include <bits/stdc++.h>
using namespace std;
class Node{//Linked list node
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
int main(){
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    a.next=&b;
    b.next=&c;
    c.next=&d;
    cout<<(((a.next)->next)->next)->val;//40
    //Node temp=a;
    // while(temp.next!=NULL){
    //     cout<<temp.val<<"  ";
    //     temp=*(temp.next);
    // }
}