#include <bits/stdc++.h>
using namespace std;
/*class MinStack { //method 1 Tc=O(1);Sc=O(n)
public:
    stack<int> st;
    stack<int> helper;
    MinStack() {//constructor
        
    }
    
    void push(int val) {//O(1)
        st.push(val);
        if(helper.size()==0 || val<helper.top()) helper.push(val);
        else helper.push(helper.top());
    }
    
    void pop() {//O(1)
        st.pop();
        helper.pop();
    }
    
    int top() {//O(1)
        return st.top();
    }
    
    int getMin() {
        return helper.top();
    }
};*/

// class MinStack {
// public:
//     vector<int> v;
//     MinStack() {//constructor      
//     }   
//     void push(int val) {//O(1)
//         v.push_back(val);
//     }   
//     void pop() {//O(1)
//        v.pop_back();
//     }   
//     int top() {//O(1)
//         return v[v.size()-1];
//     }  
//     int getMin() {
//        int mn=v[0];
//        for(int i=1;i<v.size();i++){
//         mn=min(mn,v[i]);
//        }
//        return mn;
//     }
// };

class MinStack {//Tc=O(1)  Sc=O(1)
public:
    stack<long long> st;
    long long min;
    MinStack() {//constructor
        min=LLONG_MAX;   
    }
    
    void push(int val) {//O(1)
        long long x=(long long)val;
       if(st.size()==0){
        st.push(x);
        min=x;
       }
       else if(x>=min) st.push(x);
       else{
        st.push(2*x-min);
        min= x;
       }
    }
    
    void pop() {//O(1)
      if(st.top()<min) {//st.top()>=min  : Fake value present
            //before popping make sure to retrieve the old min
            long long oldmin=2*min-st.top();
            min=oldmin;   
        }
        st.pop();
    }
    
    int top() {//O(1)
        if(st.top()<min) return (int)min;
        else return (int)(st.top());
    }
    
    int getMin() {
       return (int)min;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Minimum element: " << minStack.getMin() << endl; // Returns -3
    minStack.pop();
    cout << "Top element: " << minStack.top() << endl; // Returns 0
    cout << "Minimum element: " << minStack.getMin() << endl; // Returns -2
    
    return 0;
}