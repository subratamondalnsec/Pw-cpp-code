#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={10,2,5,6,1,0,11};
    priority_queue<int,vector<int> ,greater<int> >pq;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++) pq.push(arr[i]);
    while (!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}