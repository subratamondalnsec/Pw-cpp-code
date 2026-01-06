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
void removekthElement(stack<int>& st,int idx){
    stack<int> temp;
    if(st.size()<idx) cout<<" invalid index";
    else{
        idx--;
        while(idx){
        temp.push(st.top());
        st.pop();
        idx--;
        }
        st.pop();
      while(temp.size()){
            st.push(temp.top());
            temp.pop();
        }
    }
}
int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    print(st);
    removekthElement(st,2);
    print(st);
}