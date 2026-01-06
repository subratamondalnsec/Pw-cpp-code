#include <bits/stdc++.h>
using namespace std;
void removones(int arr[],int n,int idx){
    if(idx==n) return;
    if(arr[idx]==1)  removones(arr,n,idx+1); 
    else {
        cout<<arr[idx]<<" ";
        removones(arr,n,idx+1);
    }
}
int main(){
    int arr[]={1,2,3,1,4,5,1,70,6,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    removones(arr,n,0);
    cout<<endl;
    }