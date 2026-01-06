#include <bits/stdc++.h>
using namespace std;
class Node{//user defind data type
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class MyLinkedList {
public:    
    Node* head;
    int size;
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int idx) {
        if(idx<0||idx>=size)return -1;
        else if(idx==0) return head->val;
        else{
            Node* temp=head;
            for(int i=1;i<=idx;i++){
                temp= temp->next;
            }
            return temp->val;
        }
    }
    
    void addAtHead(int val) {
        Node* temp= new Node(val);
            if(size==0) head=temp;
            else{
                temp->next=head;
                head =temp;
            }
            size++;
        }
    
    void addAtTail(int val) {
        Node* t= new Node(val);
            if(size==0) head=t;
            else{
                Node* temp= head;
                while (temp->next!=NULL) {
                    temp = temp->next;
                }
                temp->next = t;
            }
            size++;
    }
    
    void addAtIndex(int idx, int val) {
            if(idx<0||idx>size) return;
           else if(idx==0) addAtHead( val);
            else if(idx==size) addAtTail(val);
            else {
            Node* t= new Node(val);
            Node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            size++;
            }
        
    }
    
    void deleteAtIndex(int idx) {
            if(idx<0||idx>=size) return;
            else if(size==0) return ;       
            else if(idx==0){
                head=head->next;
                size--;
            }
            else if(idx==size-1){
                Node* temp=head;
               while(temp->next->next!=NULL){
                   temp= temp->next;
                }
                temp->next=NULL;
                size--;
            }
            else{
                Node* temp=head;
                for(int i=1;i<=idx-1;i++){
                   temp= temp->next;
                }
                temp->next=temp->next->next;
                size--;
            }
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
    MyLinkedList ll;
    ll.addAtHead (15);
    ll.addAtHead (10);
    ll.display();
    ll.addAtTail (20);
    ll.addAtTail (30);
    ll.addAtTail (50);
    ll.addAtHead (5);
    ll.addAtIndex(4,25);
    cout<<ll.get(3)<<endl;
    ll.display();
    ll.deleteAtIndex(0);
    ll.display();
    ll.deleteAtIndex(2);
    ll.display();
    ll.deleteAtIndex(4);
    ll.display();
}