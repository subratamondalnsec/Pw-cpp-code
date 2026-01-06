#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={10,2,-4,5,18,24,1,-7,56};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k) pq.pop();
    }
    cout<<pq.top();
}