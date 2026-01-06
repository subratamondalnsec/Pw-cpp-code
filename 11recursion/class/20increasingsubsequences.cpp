#include <bits/stdc++.h>
using namespace std;
void printsubset(int arr[],int n,int idx, vector<int>ans,int k){
   if(idx==n){
        if(ans.size()==k) {
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(ans.size()+(n-idx)<k) return;
    printsubset(arr,n,idx+1,ans,k);
    ans.push_back(arr[idx]);
    printsubset(arr,n,idx+1,ans,k);
}
int main(){
    int arr[]={1,2,3,4,5};
     int n=sizeof(arr)/sizeof(arr[0]);
     vector<int>v;
     int k=3;
     printsubset(arr,n,0,v,k);
}