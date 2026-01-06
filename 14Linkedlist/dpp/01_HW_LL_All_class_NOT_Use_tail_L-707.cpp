#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class LinkedList{
public:
    Node* head;
    int size;
    LinkedList(){
        head=NULL;
        size=0;
    }
    void insertAThead(int val){
        Node* temp=new Node(val);
        if(size==0) head=temp;
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void insertATtail(int val){
        Node* temp=new Node(val);
        if(size==0) head=temp;
        else{
            Node* t=head;
            while(t->next!=NULL) t=t->next;
            t->next=temp;
        }
        size++;
    }
    void insertATanypoint(int val,int idx){
        if(idx<0 && idx>=size) cout<<"invalid index ";
        else if(idx==0) insertAThead(val);
        else if(idx==size-1) insertATtail(val);
        else{
            Node* temp=new Node(val);
            Node* t=head;
            for(int i=1;i<idx;i++){
                t=t->next;
            }
            temp->next=t->next;
            t->next=temp;
            size++;
        }
    }
    int get(int idx){
        if(idx==0) return head->val;
        Node* t=head;
        for(int i=1;i<=idx;i++){
            t=t->next;
        }
        return t->val;
    }
    void deleteAtidx(int idx){
        if(size==0) cout<<"LinkedList is empty";
        else if(idx<0 && idx>=size) cout<<"invalid index ";
        else if(idx==0) head=head->next;
        else{
            Node* t=head;
            for(int i=1;i<idx;i++){
                t=t->next;
            }
            t->next=t->next->next;
        }
        size--;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList ll;
    ll.insertAThead (15);
    ll.insertAThead (10);
    ll.display();
    ll.insertATtail (20);
    ll.insertATtail (30);
    ll.insertATtail (50);
    ll.insertAThead (5);
    ll.display();
    ll.insertATanypoint(25,4);
    ll.display();
    cout<<ll.get(3)<<endl;
    ll.display();
    ll.deleteAtidx(0);
    ll.display();
    ll.deleteAtidx(2);
    ll.display();
    ll.deleteAtidx(4);
    ll.display();
}