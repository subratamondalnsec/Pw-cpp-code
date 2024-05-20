#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
     cout<<"Numder of colums of *:";
        cin>>a;
    for(int i=1;i<=a;i++){//using doudle loop
         for(int j=1;j<=a;j++){
        if((i==j)||(i+j)==a+1) cout<<"*";
        else cout<<" ";
    }
    cout<<endl;
    }
}