#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
     cout<<"Numder of colums of *:";
        cin>>a;
    for(int i=1;i<=a;i++){
         for(int j=1;j<=a-i;j++){
        cout<<" ";
         }
       for(int k=1;k<=a;k++){
        cout<<"*";
    }
    cout<<endl;
    }
}