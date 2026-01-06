#include <bits/stdc++.h>
using namespace std;
void subarray(int arr[],int n,int idx, vector<int>v){
   if(idx==n){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }
    subarray(arr,n,idx+1,v);
    if((v.size()==0) || (v[v.size()-1]==arr[idx-1])){
        v.push_back(arr[idx]);
        subarray(arr,n,idx+1,v);   
    }  
}
int main(){
    int arr[]={1,2,3,4};
     int n=sizeof(arr)/sizeof(arr[0]);
     vector<int>v;
     subarray(arr,n,0,v);
}