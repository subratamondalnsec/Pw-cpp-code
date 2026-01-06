#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={4, 2, 7, 9, 8};
    int n =sizeof(arr)/sizeof(arr[0]);
    bool flag=true;
    for(int i=0;i<n-1;i++){  
       if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            i++;
       }
    }
    for(int i=0;i<n;i++){  
       if(arr[i]>arr[i+1]){
            flag=false;
            break;
       }
    }
    flag ? cout<<"almost sorted":cout<<"almost not sorted";
}