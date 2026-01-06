#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,3,4,4,4,5};
    int n =sizeof(arr)/sizeof(arr[0]);
    int x=4;
    int lo=0;
    int hi=n-1;
   bool flag=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==x){
        if(arr[mid+1]!=x){
             flag=true;
             cout<<mid;
             break;
             }
             else lo=mid+1;
        }
        else if(arr[mid]>x)hi=mid-1;
        else lo=mid+1;
    }
    if(flag==false) cout<<-1;
}