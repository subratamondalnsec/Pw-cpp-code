#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    int front=-1;
    int rear=-1;
    int size;//curr size
    int curr=0;//capasity
    vector<int>arr;
    MyCircularDeque(int k) {
       arr.resize(k);
       size=k;
    }
    bool insertFront(int val) {
        if(isFull()) return false;
        if(front==-1 and rear==-1){
            front=rear=0;
            arr[front]=val;
        }
        else if(front==0){
            front=size-1;
            arr[front]=val;
        }
        else{
            front=front-1;
            arr[front]=val;
        }
        curr++;
        return true;
    }
    
    bool insertLast(int val) {
        if(isFull()) return false;
        if(front==-1 and rear==-1){
            front=rear=0;
            arr[rear]=val;
        }
        else if(rear==size-1){
            rear=0;
            arr[rear]=val;
        }
        else{
            rear=rear+1;
            arr[rear]=val;
        }
        curr++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        if( front==size-1) front=0;
        else  front= front+1;
        curr--;
        return true;
    }
    
    bool deleteLast() {
         if(isEmpty()) return false;
        if( rear==0) rear=size-1;
        else  rear= rear-1;
        curr--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return (curr==0);
    }
    
    bool isFull() {
        return (curr==size);
    }
};

class MyCircularDeque {
public:
    int f;
    int b;
    int s;//curr size
    int c;//capasity
    vector<int>arr;
    MyCircularDeque(int k) {
        f = 0;
        b = 0;
        s=0;
        c=k;
        vector<int>v(k);
        arr=v;
    }
    
    bool insertFront(int val) {
        if(s==c) return false;
        f--;
        if(f==-1) f=c-1;
        arr[f]=val;
        s++;
        return true;
    }
    
    bool insertLast(int val) {
        if(s==c) return false;
        arr[b]=val;
        b++;
        if(b==c) b=0;
        s++;
        return true;
    }
    
    bool deleteFront() {
        if(s==0) return false;
        f++;
        if(f==c) f=0;
        s--;
        return true;
    }
    
    bool deleteLast() {
        if(s==0) return false;
        b--;
        if(b==-1) b=c-1;
        s--;
        return true;
    }
    
    int getFront() {
        if(s==0) return -1;
        return arr[f];
    }
    
    int getRear() {
        if(s==0) return -1;
        if(b==0) return arr[c-1];
        return arr[b-1];
    }
    
    bool isEmpty() {
        return (s==0);
    }
    
    bool isFull() {
        return (s==c);
    }
};

int main() {
    MyCircularDeque deque(5);  // Create a deque with capacity 5
    
    cout << boolalpha;  // To print boolean values as true/false instead of 1/0
    
    // Insert elements at the front
    cout << "Insert 10 at front: " << deque.insertFront(10) << endl;  // true
    cout << "Insert 20 at front: " << deque.insertFront(20) << endl;  // true

    // Insert elements at the rear
    cout << "Insert 30 at rear: " << deque.insertLast(30) << endl;  // true
    cout << "Insert 40 at rear: " << deque.insertLast(40) << endl;  // true
    cout << "Insert 50 at rear: " << deque.insertLast(50) << endl;  // true
    cout << "Insert 60 at rear (expect fail): " << deque.insertLast(60) << endl;  // false (deque is full)

    // Check the front and rear values
    cout << "Front element: " << deque.getFront() << endl;  // 20
    cout << "Rear element: " << deque.getRear() << endl;    // 50

    // Delete elements from the front and rear
    cout << "Delete front: " << deque.deleteFront() << endl;  // true
    cout << "Delete rear: " << deque.deleteLast() << endl;    // true
    
    // Check if deque is empty or full
    cout << "Is deque empty: " << deque.isEmpty() << endl;    // false
    cout << "Is deque full: " << deque.isFull() << endl;      // false
    
    // Final front and rear after deletion
    cout << "Front element: " << deque.getFront() << endl;  // 10
    cout << "Rear element: " << deque.getRear() << endl;    // 40

    return 0;
}