#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={5,4,5,5,3,2,1};
    int n =sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){   //optimised   
        int j=i;
        while (j>=1&&arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    int s1=0;
    for(int i=0;i<n;i++){
        s1*=10;
        s1+=arr[i];
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]!=arr[i-1]){
            swap(arr[i],arr[i-1]);
            break;
        }
    }
    int s2=0;
    for(int i=0;i<n;i++){
        s2*=10;
        s2+=arr[i];
    }
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<"Minimum sum of array"<<s1+s2<<endl;
}