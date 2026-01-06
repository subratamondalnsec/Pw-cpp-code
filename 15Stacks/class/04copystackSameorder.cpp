#include <bits/stdc++.h>
using namespace std;
void print (stack<int>st){
    stack<int> temp;
    while(st.size()){//  empty 
        temp.push(st.top());
        st.pop();
    }
    while(temp.size()){// loaded stack
        cout <<temp.top()<<"  ";//normal order
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl;
}
int main(){
    stack<int> st;
    stack<int> temp1;
    stack<int> temp2;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    print(st);
    while(st.size()){
        temp1.push(st.top());
        st.pop();
    }
    while(temp1.size()){
        temp2.push(temp1.top());
        temp1.pop();
    }
    print(temp2);
}