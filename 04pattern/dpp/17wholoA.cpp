#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
    cout<<"Numder of colums of *:";
        cin>>n;
        for(int i=1;i<=n-1;i++) cout<<" ";
        cout<<"1";
        cout<<endl;
        for(int i=2;i<=n;i++){
             for(int j=1;j<=n-i;j++){
                cout<<" ";
            }
            cout<<i;
            for(int j=1;j<=2*(i-1)-1;j++){
                cout<<" ";
            }
            cout<<i;
            cout<<endl;
        }
}