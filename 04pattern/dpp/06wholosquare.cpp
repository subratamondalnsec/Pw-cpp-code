#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cout<<"Numder of row of *:";
    cin>>n;
     cout<<"Numder of colums of *:";
        cin>>m;
    for(int i=1;i<=m;i++){//using doudle loop
         for(int j=1;j<=n;j++){
            if(i==1||j==1||i==m||j==n) cout<<" * ";
            else cout<<"   ";
        }
    cout<<endl;
    }
}