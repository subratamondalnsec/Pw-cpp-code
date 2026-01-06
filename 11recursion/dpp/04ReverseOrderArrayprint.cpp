#include<bits/stdc++.h>
using namespace std;
// void reverseorder(int arr[],int n){
//     if(n<1) return ;
//     cout<<arr[n-1]<<endl;
//     reverseorder(arr,n-1);
// }
void reverseorder(int arr[],int n,int i){
    if(i==n) return ;
    reverseorder(arr,n,i+1);
    cout<<arr[i]<<endl;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    reverseorder(arr,n,0);
}