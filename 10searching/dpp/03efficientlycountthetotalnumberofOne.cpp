#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={0,0,0,0,1,1};
    int n =sizeof(arr)/sizeof(arr[0]);
    int lo=0;
    int hi=n-1;
    bool flag=false;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==1){
        if(arr[mid-1]!=1){
             flag=true;
             ans=mid;
             break;
             }
             else lo=mid+1;
        }
        else if(arr[mid]>1)hi=mid-1;
        else lo=mid+1;
    }
    if(flag==false) cout<<-1;
    else cout<<"Total number of 1's : "<<n-ans;
}