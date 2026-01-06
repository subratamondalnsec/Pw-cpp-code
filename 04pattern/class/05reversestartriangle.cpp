#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;

     cout<<"Numder of colums of *:";
        cin>>a;
    for(int i=1;i<=a;i++){//using doudle loop
         for(int j=1;j<=a+1-i;j++){//for(int j=i;j<=a;j++)
        cout<<" * ";
    }
    cout<<endl;
    }
}