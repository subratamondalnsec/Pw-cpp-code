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
class LinkedList{//user defind data structure
public:
    Node* head;
    Node* tail;
    int size;
        LinkedList(){
            head=tail=NULL;
            size=0;
        }
        void insertAtbegginning (int val){
            Node* temp= new Node(val);
            if(size==0) head=tail=temp;
            else{
                temp->next=head;
                head =temp;
            }
            size++;
        }
        void insertAtEnd(int val){
            Node* temp= new Node(val);
            if(size==0) head=tail=temp;
            else{
                tail->next=temp;
                tail =temp;
            }
            size++;
        }
        void insertAtanypoint(int idx,int val){
            if(idx<0||idx>size) cout<<"invalid index"<<endl;
            else if(idx==0) insertAtbegginning( val);
            else if(idx==size) insertAtEnd(val);
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
        int getAtelement(int idx){
            if(idx<0||idx>=size){
                cout<<"invalid index";
                return -1;
            }
            else if(idx==0) return head->val;
            else if(idx==size-1) return tail->val;
            else{
                Node* temp=head;
                for(int i=1;i<=idx;i++){
                   temp= temp->next;
                }
                return temp->val;
            }
        }
        void deleteAtHead(){
            if(size==0){
                cout<<"Linkedlist is empty";
                return ;
            }
            head=head->next;
            size--;
        }
        void deleteAttail(){
            if(size==0){
                cout<<"Linkedlist is empty";
                return ;
            }
             Node* temp=head;
               while(temp->next!=tail){
                   temp= temp->next;
                }
                temp->next=NULL;
                tail=temp;
                size--;
            }
        void deleteAtanyidx(int idx){
            if(size==0){
                cout<<"Linkedlist is empty";
                return ;
            }
            else if(idx==0) return deleteAtHead();
            else if(idx==size-1) return deleteAttail();
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
    LinkedList ll;
    ll.insertAtbegginning (10);
    ll.display();
    ll.insertAtEnd (20);
    ll.insertAtEnd (30);
    ll.insertAtEnd (50);
    ll.insertAtbegginning (5);
    ll.insertAtanypoint(2,15);
    cout<<ll.getAtelement(3)<<endl;
    ll.display();
    ll.deleteAtHead();
    ll.display();
    ll.deleteAttail();
    ll.display();
    ll.deleteAtanyidx(2);
    ll.display();
}