#include <bits/stdc++.h>
using namespace std;
void displayarr(int arr[],int n,int idx){
    if(idx==n) return;
    cout<<arr[idx]<<" ";
      displayarr(arr,n,idx+1);
}
void displayvector(vector<int>&v,int idx){
    if(idx==v.size()) return;
    cout<<v[idx]<<" ";
      displayvector(v,idx+1);
}
int main(){
    int arr[]={2,3,4,5,7,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        v[i]=arr[i];
    }
    displayarr(arr,n,0);
    cout<<endl;
    displayvector(v,0);
}