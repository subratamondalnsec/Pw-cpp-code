#include<bits/stdc++.h>
using namespace std;
int main(){//output 
    int arr[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            arr[i][j]=10;
        } 
    }
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            cout<<arr[i][j]<<" ";
        } 
    cout<<endl;   
    }
}