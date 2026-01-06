#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,5,7,8};
    int n =sizeof(arr)/sizeof(arr[0]);
    int ans=-1;
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==mid) lo=mid+1;
        else{
            ans=mid;
            hi=mid-1;
        }
    }
    cout<<ans;
}