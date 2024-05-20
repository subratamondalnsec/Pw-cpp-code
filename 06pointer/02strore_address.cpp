#include<bits/stdc++.h>
using namespace std;
int main(){
    int x=4;
    float y=3.1;
    bool f=true;
    char z='a';
    int* p=&x;//store the address
    float* q=&y;
    char*r = &z;
    cout<<*p<<endl<<*q<<endl<<*r<<endl<<f;

    *p=9;//update the value
    *q=7.1;
    *r='g';
    cout<<*p<<endl<<*q<<endl<<*r<<endl;

    *q=*p+*q;//operator
     cout<<*p<<endl<<*q<<endl<<*r<<endl;
     cin>>*p>>*q>>*r;
     cout<<*p<<endl<<*q<<endl<<*r<<endl;

    }