#include <bits/stdc++.h>
using namespace std;
void maxarray(int arr[],int n,int idx,int max){
    if(idx==n){
        cout<<max;
        return;
    }
    if(max<arr[idx]) max=arr[idx];
    maxarray(arr,n,idx+1,max);
}
void maxvector(vector<int>&v,int idx,int max){
    if(idx==v.size()){
        cout<<max;
        return;
        }
    if(max<v[idx]) max=v[idx];
    maxvector(v,idx+1,max);  
}
int builtmax(int arr[],int n,int idx){
      if(idx==n) return INT_MIN;
      return max(arr[idx],builtmax(arr,n,idx+1));
    }
int main(){
    int arr[]={2,3,4,5,70,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v(n);
    for(int i=0;i<n;i++){
        v[i]=arr[i];
    }
    maxarray(arr,n,0,INT_MIN);
    cout<<endl;
    maxvector(v,0,INT_MIN);
    cout<<endl<<builtmax(arr, n,0);
}