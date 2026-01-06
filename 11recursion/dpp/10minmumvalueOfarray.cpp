#include <bits/stdc++.h>
using namespace std;
void minarray(int arr[],int n,int idx,int min){
    if(idx==n){
        cout<<min;
        return;
    }
    if(min>arr[idx]) min=arr[idx];
    minarray(arr,n,idx+1,min);
}
void minvector(vector<int>&v,int idx,int min){
    if(idx==v.size()){
        cout<<min;
        return;
    }
    if(min>v[idx]) min=v[idx];
    minvector(v,idx+1,min);  
}
int builtmin(int arr[],int n,int idx){
      if(idx==n) return INT_MAX;
      return min(arr[idx],builtmin(arr,n,idx+1));
    }
int main(){
    int arr[]={2,3,4,5,70,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        v[i]=arr[i];
    }
    minarray(arr,n,0,INT_MAX);
    cout<<endl;
    minvector(v,0,INT_MAX);
    cout<<endl<<builtmin(arr, n,0);
}