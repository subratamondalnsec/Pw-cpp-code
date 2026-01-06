#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q.size()==0) q.push(x);
        else{
            q.push(x);
            int n= q.size();
            for(int i=1;i<n;i++){
                q.push(q.front());
                q.pop();
            }
        }
    }
    
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front() ;
    }
    
    bool empty() {
        return q.empty();
    }
};

class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n= q.size();
        for(int i=1;i<n;i++){
            q.push(q.front());
            q.pop();
        }
        int x=q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.back() ;
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack stack;

    // Push elements into the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Show the top element
    cout << "Top element: " << stack.top() << endl;  // Should print 30

    // Pop element from the stack
    cout << "Popped element: " << stack.pop() << endl;  // Should print 30

    // Show the top element after popping
    cout << "Top element: " << stack.top() << endl;  // Should print 20

    // Check if stack is empty
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;  // Should print No

    // Pop remaining elements
    stack.pop();
    stack.pop();

    // Check if stack is empty after popping all elements
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;  // Should print Yes

    return 0;
}