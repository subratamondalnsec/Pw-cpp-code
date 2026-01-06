#include <iostream>
#include <vector>
using namespace std;
class Stack{
public:
    vector<int> v;
    Stack(){
    }
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        if(v.size()==0){
            cout<<"stack is empty";
            return;
        }
        v.pop_back();
    }
    int top(){
        if(v.size()==0){
            cout<<"stack is empty";
            return-1;
        }
        return v[v.size()-1];
    }
    int size(){
        return v.size();
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(20);
    st.push(30);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    st.push(30);
    st.push(30);
    st.push(30);
}