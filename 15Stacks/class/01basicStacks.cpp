#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    cout <<st.size();
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    cout <<endl<<st.size();
    st.pop();
    cout <<endl<<st.size();
    cout <<endl<<st.top();
}
