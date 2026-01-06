#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the array size: ";
    cin>>n;
    int arr[n];
    cout<<"enter the array element: ";
    for(int i=0;i<=n-1;i++){
      cin>>arr[i];
    }
    bool flag=true;
    for(int i=1;i<n;i++){
       if(arr[i-1]>arr[i]){
        flag = false;
        break;
       } 
    }
    if(flag==false) cout<<"it not sorted order";
    else cout<<"it sorted order";
}