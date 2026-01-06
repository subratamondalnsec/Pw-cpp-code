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
    int x;
    cout<<"target:";
    cin>>x;
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==x) count++;
            }
        }
    }
    cout<<count; 
}