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
    for(int i=0;i<n;i++){
        if(i%2==0) arr[i]+=10;
        else arr[i]*=2;
    }
    for(int i=0;i<=n-1;i++){
      cout<<arr[i]<<" ";
    }
}