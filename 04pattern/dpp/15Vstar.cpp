#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
    cout<<"Numder of colums of *:";
        cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=2;j<=i;j++){
            cout<<" "; 
        }
        //for(int k=i;k<=i;k++){
            cout<<"*";
        //}
        for(int j=1;j<=2*(n-i)-1;j++){
            cout<<" "; 
        }
       // for(int k=i;k<=i;k++){
            if(i==n) continue;
            cout<<"*";
        //}
        cout<<endl;
    }
    
}