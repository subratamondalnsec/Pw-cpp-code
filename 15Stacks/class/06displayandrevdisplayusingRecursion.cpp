#include <bits/stdc++.h>
using namespace std;
void displayRev(stack<int>& st){
    if(st.size()==0) return;
    int x= st.top();
    cout<<x<<"  ";
    st.pop();
    displayRev(st);
    st.push(x);
}
void display(stack<int> & st){
    if(st.size()==0) return;
    int x= st.top();
    st.pop();
    display(st);
    cout<<x<<"  ";
    st.push(x);
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
    display(st); 
    cout<<endl;
    displayRev(st);
}