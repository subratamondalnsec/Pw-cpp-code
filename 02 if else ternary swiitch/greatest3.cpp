#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,y,z;
    cout<<"enter the 1st numder :";
    cin>>x;
       cout<<"enter the 2nd numder :";
    cin>>y;   
    cout<<"enter the 3rd numder :";
    cin>>z;
    if(x>y&&x>z){
        cout<<"greatest :"<<x;

    }else if(y>z){
         cout<<"greatest :"<<y;
     

    }else
     cout<<"greatest :"<<z;
}