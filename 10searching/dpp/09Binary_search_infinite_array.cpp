#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int x=5;
    int lo=0;
    int hi=2;
    bool flag =false;
    while(arr[hi]<x){
        lo=hi;
        hi*=2;
    }
    if(arr[lo]<=x && x<=arr[hi]){
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==x){
                cout<<arr[mid];
                flag=true;
                break;
                }
            else if(arr[mid]>x)hi=mid-1;
            else lo=mid+1;
        }
    }
    if(flag==true) cout<<" present";
    else cout<<" not present";
}