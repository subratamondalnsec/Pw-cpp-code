#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the integer : ";
    cin>>n;
    if(n & (n-1)==0) cout<<"YES,The number is a power of two";
    else cout<<"No,The number is not a power of two";
}