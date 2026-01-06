#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int>pq;//max heap
    priority_queue<int,vector<int>,greater<int> >min;//min heap
    pq.push(10);
    pq.push(15);
    pq.push(1);
    pq.push(150);
    pq.push(12);
    pq.push(19);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    min.push(10);
    min.push(-1);
    min.push(-10);
    min.push(15);
    min.push(19);
    min.push(1);
    cout<<min.top()<<endl;
    min.pop();
    cout<<min.top()<<endl;
}