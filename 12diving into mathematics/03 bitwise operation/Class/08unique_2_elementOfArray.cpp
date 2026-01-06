#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={2,3,6,5,4,9,8,7,2,3,4,5,6,7,8,9,12,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    int res=0;
    for(int i=0;i<n;i++){
        res=res^arr[i];
    }
    int temp=res,k=0;
    while(true){
        if((temp & 1)==1){
            break;
        }
        temp=temp >>1;
        k++;
    }
    int retval=0;
     for(int i=0;i<n;i++){
       int num=arr[i];
       if(((num>>k) & 1)==1) retval ^=num;
    }
    cout<<retval<<"  ";
    res=retval^res;
    cout<<res<<" ";
}