#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={4, 2, 7, 9, 8};
    int n =sizeof(arr)/sizeof(arr[0]);
    int brr[n];
    for(int i=0;i<n;i++){
        brr[i]=arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n-1;i++){ // first side method 1
    bool flag=true;      
        for(int j=0;j<n-1-i;j++){//traverse
            if(brr[j]>brr[j+1]){
                swap(brr[j],brr[j+1]);//
                flag=false;
            }
        }
        if(flag==true) break;
    }
    for(int i=0;i<n;i++){
        cout<<brr[i]<<" ";
    }
    cout<<endl;
    bool flag=true;
    //arr 4 2 7 8 9
    //brr 2 4 7 8 9
    for(int i=0;i<n-1;i++){
        if(i==0){
            if(arr[i]!=brr[i] && arr[i]!=brr[i+1] ){
                flag=false;
                break;
            }
        }
        else if(i==n-1){
            if(arr[i]!=brr[i] && arr[i]!=brr[i-1] ){
                flag=false;
                break;
            }
        }
        else {
            if(arr[i]!=brr[i] && arr[i]!=brr[i+1] && arr[i]!=brr[i-1]){
                flag=false;
                break;
            }
        }
    }
    flag ? cout<<"almost sorted":cout<<"almost not sorted";
}