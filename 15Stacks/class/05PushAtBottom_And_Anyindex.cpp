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
void PushAtBottom(stack<int>& st,int val){//call by referense
    stack<int> temp;
    while(st.size()){//  empty 
    temp.push(st.top());
    st.pop();
    }
    st.push(val);
    while(temp.size()){
    st.push(temp.top());
    temp.pop();
    }
}
void PushAtBottomrec(stack<int>& st,int val){//RECURSION METHOD
    if(st.size()==0) {
        st.push(val);
        return;
    }
    int x= st.top();
    st.pop();
    PushAtBottomrec(st,val);
    st.push(x);
}
void Anyindex(stack<int>& st,int val,int idx){
    stack<int> temp;
    if(st.size()<idx) cout<<" invalid index";
    else{
        idx=st.size()-idx;
        while(idx){
        temp.push(st.top());
        st.pop();
        idx--;
        }
        st.push(val);
      while(temp.size()){
            st.push(temp.top());
            temp.pop();
        }
    }
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
    PushAtBottom(st,5);
    PushAtBottomrec(st,2);
    Anyindex(st,35,5);
    print(st);
}

