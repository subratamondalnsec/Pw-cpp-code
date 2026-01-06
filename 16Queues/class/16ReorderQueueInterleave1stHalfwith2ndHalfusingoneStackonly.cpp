#include <bits/stdc++.h>
using namespace std;
void display( queue<int>& q){
    int n=q.size();
    for(int i=1;i<=n;i++){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}
void reorder(queue<int>& q){
    stack<int>st;
    int n=q.size();
    for(int i=1;i<=n/2;i++){//1st half q->st;
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){//elment st->q
        q.push(st.top());
        st.pop();
    }
    for(int i=1;i<=n-n/2;i++){//2nd half q->st;
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){//alternate aterching
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    //revevese
    for(int i=1;i<=n;i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    display(q);
    reorder(q);
    display(q);
}