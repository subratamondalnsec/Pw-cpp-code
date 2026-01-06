#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int n =sizeof(arr)/sizeof(arr[0]);
    int x=5;
    int lo=0;
    int hi=n-1;
   bool flag=false;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]==x){
             cout<<arr[mid];
             flag=true;
             break;
             }
        else if(arr[mid]>x)lo=mid+1;
        else hi=mid-1;
    }
    if(flag==true) cout<<" present";
    else cout<<" not present";
}