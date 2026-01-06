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

class DoublyLinkedList{//user defind data structure
public:
    Node* head;
    Node* tail;
    int size;
        DoublyLinkedList(){
            head=tail=NULL;
            size=0;
        }
        void insertAtbegginning (int val){
            Node* temp= new Node(val);
            if(size==0) head=tail=temp;
            else{
                temp->next=head;
                head->prev=temp;
                head =temp;
            }
            size++;
        }
        void insertAtEnd(int val){
            Node* temp= new Node(val);
            if(size==0) head=tail=temp;
            else{
                tail->next=temp;
                temp->prev=tail;//extra
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
                t->prev=temp;
                t->next->prev=t;
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
                if(idx<size/2){
                    Node* temp=head;
                    for(int i=1;i<=idx;i++){
                        temp= temp->next;
                    }
                    return temp->val;
                }
                else{
                    Node* temp=tail;
                    for(int i=1;i<size-idx;i++){
                        temp= temp->prev;
                    }
                    return temp->val;
                }
            }
        }
        void deleteAtHead(){
            if(size==0){
                cout<<"Linkedlist is empty";
                return ;
            }
            head=head->next;
           if(head!=NULL) head->prev=NULL;
           if(head==NULL) tail = NULL;
            size--;
        }
        void deleteAttail(){
            if(size==0){
                cout<<"Linkedlist is empty";
                return ;
            }
             else  if(size==1){
                deleteAtHead();
                return;
            }
            Node* temp=tail->prev;
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
                temp->next->prev=temp;
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
    DoublyLinkedList dll;
    dll.insertAtbegginning (10);
    dll.insertAtEnd (20);
    dll.insertAtEnd (30);
    dll.insertAtEnd (50);
    dll.insertAtbegginning (2);
    dll.insertAtEnd (60);
    dll.insertAtEnd (70);
    dll.insertAtEnd (80);
    dll.insertAtbegginning (5);
    dll.insertAtanypoint(2,15);
    dll.display();
    dll.deleteAtHead();
    dll.display();
    dll.deleteAttail();
    dll.display();
    dll.deleteAtanyidx(2);
    dll.display();
    cout<<dll.getAtelement(4)<<endl;
    dll.display();
}