#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,1,2,3,4,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        int count =0;
        for(int j=0;j<n;j++){
            if((i!=j)&& arr[i]==arr[j]) count++;
           
        }
        if(count==0){
            cout<<arr[i];
            break;
        }
    }
}