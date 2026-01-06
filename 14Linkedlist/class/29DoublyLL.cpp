#include <bits/stdc++.h>
using namespace std;
class Node{//Linked list node
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
void display(Node* head){
     while(head!=NULL){
         cout<<head->val<<"  ";
         head=head->next;
    }
    cout<<endl;
}
void displayreverse(Node* tail){
     while(tail!=NULL){
         cout<<tail->val<<"  ";
         tail=tail->prev;
    }
    cout<<endl;
}
int main(){
    Node* a= new Node(10);
    Node* b= new Node(20);
    Node* c= new Node(30);
    Node* d= new Node(40);
    Node* e= new Node(50);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->prev=d;
    d->prev=c;
    c->prev=b;
    b->prev=a;
    display(a);
    displayreverse(e);
}