#include <bits/stdc++.h>
using namespace std;
void dec_to_binary(int m){
    if(m==0) return ;
    dec_to_binary(m/2);
    cout<<m%2;
}
int main(){
    int m;
    cout<<"enter the decimal number : ";
    cin>>m;
    dec_to_binary(m);
}