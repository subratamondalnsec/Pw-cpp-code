#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,2,3,3,3,3,5,7,8};
    int n =sizeof(arr)/sizeof(arr[0]);
    int x=3;
    int lo=0;
    int hi=n-1;
   bool flag=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==x){
            if(mid==n-1 || arr[mid+1]!=x){
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