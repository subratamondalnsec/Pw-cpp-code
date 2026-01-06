#include<bits/stdc++.h>
using namespace std;
int main(){//output 
    int arr[3][3]={1,2,3,4,5,6,7,8,9};
    for(int i=0;i<=2;i++){
    for(int j=0;j<=2;j++){
        cout<<arr[i][j]<<" ";
    } 
    cout<<endl;   
    }
    int i,j;//input of 2d array
     int brr[3][3];
    for(int i=0;i<=2;i++){
    for(int j=0;j<=2;j++){
        cin>>brr[i][j];
    } 
    cout<<endl;   
    }
     for(int i=0;i<=2;i++){
    for(int j=0;j<=2;j++){
        cout<<brr[i][j]<<" ";
    } 
    cout<<endl;   
    }
}