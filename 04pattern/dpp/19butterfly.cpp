#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
    cout<<"Numder of colums of *:";
        cin>>n;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int k=1;k<=2*(n-i)-1;k++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=2*n-1;i++){
        cout<<"*"; 
    }
    cout<<endl;
    for(int i=1;i<=2*n-1;i++){
        cout<<"*"; 
    }
    cout<<endl;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            cout<<"*";
        }
        for(int k=1;k<=2*i-1;k++){
            cout<<" ";
        }
        for(int j=1;j<=n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
}