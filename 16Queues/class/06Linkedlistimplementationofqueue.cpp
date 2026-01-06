#include<iostream>
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
class Queue{
public:
    Node* head;
    Node* tail;
    int s;
    Queue(){
       head=tail=head;
       s=0;
    }
    void push(int val){
        Node* temp=new Node(val);
        if(s==0) head=tail=temp;
        else{
            tail->next=temp;
            tail = temp;
        }
        s++;
    }
    void pop(){
        if(s==0){
            cout<<"Queue is EMPTY!"<<endl;
            return;
        }
        Node* temp =head;
        head=head->next;
        s--;
        delete(temp);
    }
    int front(){
        if(s==0){
            cout<<"Queue is EMPTY!"<<endl;
            return -1;
        }
        return head->val;
    }
    int back(){
        if(s==0){
            cout<<"Queue is EMPTY!"<<endl;
            return -1;
        }
        return tail->val;
    }
    int size(){
        return s;
    }
    bool empty(){
        if(s==0) return true;
        else return false;
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
    Queue q; //push pop front back size empty
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    q.pop();
    q.display();
    cout<<q.size();
}