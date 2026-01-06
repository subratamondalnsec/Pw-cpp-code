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
void diplayrecursion(Node* head){
    if(head==NULL) return;
    cout<<head->val<<"  ";
    diplayrecursion(head->next);     
}
int main(){
    Node* a= new Node(10);
    Node* b= new Node(20);
    Node* c= new Node(30);
    Node* d= new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    diplayrecursion(a);
}