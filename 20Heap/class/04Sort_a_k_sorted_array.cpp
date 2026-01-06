#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={6,5,3,2,8,9,10};
    int k=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    priority_queue<int,vector<int>,greater<int> >pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
          cout<<pq.top()<<" "; 
           pq.pop();
        } 
    }
    while(pq.size()>0){
        cout<<pq.top()<<" "; 
        pq.pop();
    }
}