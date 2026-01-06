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
        cout<<" * ";
    }
    cout<<endl;
    }
    cout<<"   method 2"<<endl;
    int con=(a*b);
    for(int i=0;i<con;i++){//using singel loop
        cout<<" * ";
        if(i%b==(b-1)){
    cout<<endl;
    }
    }
}