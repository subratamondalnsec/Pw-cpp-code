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
    int sumeven = 0;
    int sumodd=0;
    for(int i=0;i<n;i++){
        if(i%2==0) sumeven+=arr[i];
        else sumodd+=arr[i];
    }
    cout<<abs(sumeven-sumodd);
}