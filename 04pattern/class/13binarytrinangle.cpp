#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
     cout<<"Numder of colums of *:";
        cin>>a;
    for(int i=1;i<=a;i++){//using doudle loop
    //      for(int j=1;j<=i;j++){
    //      if((i+j)%2==0)
    //     cout<<"1"<<" ";
    //     else cout<<"0"<<" ";
    // }
    if(i%2!=0) b=1;
    else b=0;
     for(int j=1;j<=i;j++){
     cout<<b;
     //fliping
     if(b==1) b=0;
     else b=1;
     }
    cout<<endl;
    }
}