#include<bits/stdc++.h>
using namespace std;
int main(){
    int a;
     cout<<"Numder of colums of *:";
        cin>>a;
        int k=1;
    for(int i=1;i<=a;i++){//using doudle loop
         for(int j=1;j<=i;j++){
        cout<<k<<" ";
        k++;
    }
    cout<<endl;
    }
}