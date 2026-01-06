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
    ll.insertAtbegginning (20);
    ll.insertAtbegginning (30);
    ll.insertAtbegginning (50);
    ll.display();
}