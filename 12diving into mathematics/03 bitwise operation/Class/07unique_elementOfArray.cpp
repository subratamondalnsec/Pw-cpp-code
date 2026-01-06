#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={2,3,6,5,4,9,8,7,2,3,4,5,6,7,8,9,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    int res=0;
    for(int i=0;i<n;i++){
        res=res^arr[i];
    }
    cout<<res<<endl;
}