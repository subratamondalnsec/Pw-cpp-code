#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int n =sizeof(arr)/sizeof(arr[0]);
    int x=5;
    int lo=0;
    int hi=n-1;
   bool flag=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==x){
             cout<<arr[mid+1];
             flag=true;
             break;
             }
        else if(arr[mid]>x)hi=mid-1;
        else lo=mid+1;
    }
    if(flag==false) cout<<arr[lo];
}