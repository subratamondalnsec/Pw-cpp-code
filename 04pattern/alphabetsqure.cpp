#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cout<<"Numder of row of *:";
    cin>>b;
     cout<<"Numder of colums of *:";
        cin>>a;
    for(int i=1;i<=a;i++){//using doudle loop
         for(int j=1;j<=b;j++){
        cout<<(char)(j+64)<<" ";
    }
    cout<<endl;
    }
}