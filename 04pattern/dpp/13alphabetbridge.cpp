#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
    cout<<"Numder of colums of *:";
        cin>>n;
    int nsp=1,m=n-1,a=1;

    for(int i=1;i<=2*n-1;i++){
        cout<<(char)(a+64); 
        a++;
    }
    cout<<endl;
    for(int i=1;i<=m;i++){
        a=1;
        for(int j=1;j<=m+1-i;j++){
            cout<<(char)(a+64); 
            a++;
        }
        for(int k=1;k<=nsp;k++){
            cout<<" ";
            a++;
        }
        nsp+=2;
        for(int j=1;j<=m+1-i;j++){
            cout<<(char)(a+64); 
            a++;
        }
        cout<<endl;
    }
    
}