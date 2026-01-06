#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={4,6,3,5,2,1};
    int n =sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    // for(int i=0;i<n-1;i++){ // first side method 1
    // bool flag=true;      
    //     for(int j=0;j<n-1-i;j++){//traverse
    //         if(arr[j]<arr[j+1]){
    //             swap(arr[j],arr[j+1]);//
    //             flag=false;
    //         }
    //     }
    //     if(flag==true) break;
    // }

    for(int i=0;i<n-1;i++){
    bool flag=true;      
        for(int j=n-1;j>=1+i;j--){//traverse
            if(arr[j] > arr[j-1]){
                swap(arr[j],arr[j-1]);//
                flag=false;
            }
        }
        if(flag==true) break;
    }

    cout<<endl;
        for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}