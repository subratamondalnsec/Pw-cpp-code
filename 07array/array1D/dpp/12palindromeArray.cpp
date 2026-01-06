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
    int i=0,j=n-1;
    while(i<=j){
        if(arr[i]==arr[j]) {
            i++;
            j--;
        }
        else{
            cout<<"it not palindrome";
            return 0;
        }
    }
        cout<<"it palindrome";
}