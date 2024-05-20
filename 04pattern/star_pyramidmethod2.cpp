#include<bits/stdc++.h>
using namespace std;
int main(){
    int nst=1,n;
    cout<<"Numder of colums of *:";
        cin>>n;
    int nsp=n-1;
    for(int i=1;i<n;i++){
          for(int j=1;j<=nsp;j++){
            cout<<" ";
         }
         nsp--;
          for(int k=1;k<=nst;k++){
           cout<<"*";
         }
         nst+=2;
          cout<<endl;
    }
}