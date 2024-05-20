#include<bits/stdc++.h>
using namespace std;
int main(){//output 
   int m;
   cout<<"enter the student :";
   cin>>m;
    int i,j;//input of 2d array
     int arr[m][2];
    for(int i=0;i<m;i++){
    for(int j=0;j<2;j++){
        cin>>arr[i][j];
    } 
    cout<<endl;   
    }
    cout<<"roll mark"<<endl;
     for(int i=0;i<m;i++){//output
    for(int j=0;j<2;j++){
        cout<<arr[i][j]<<"     ";
    } 
    cout<<endl;   
    }
}

