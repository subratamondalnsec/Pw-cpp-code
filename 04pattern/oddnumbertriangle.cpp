#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;

     cout<<"Numder of colums of *:";
        cin>>n;
    for(int i=1;i<=n;i++){//using doudle loop
         for(int j=1;j<=2*i-1;j+=2){
        cout<<j<<" ";
    }
    cout<<endl;
    }
}