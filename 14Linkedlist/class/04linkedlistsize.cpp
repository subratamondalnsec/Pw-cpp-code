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
int size(Node* head){
    Node* temp=head;
    int n=0;
     while(temp!=NULL){
         cout<<temp->val<<"  ";
         temp=temp->next;
         n++;
    }
    return n;
}
int main(){
    Node* a= new Node(10);
    Node* b= new Node(20);
    Node* c= new Node(30);
    Node* d= new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    cout<<"\n size of linked list : "<<size(a);
}