#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the integer : ";
    cin>>n;
    if((n&(n-1))==0 )cout<<"YES,The number is a power of two";
    else {
        int x=n;
        int temp=0;
        while(n!=0){
            temp=n;
            n=(n & (n-1));
        }
        temp=temp<<1;
        cout<<(temp-x)<<" minimum number to be added to change it to a power of two : "<<temp;
    }
}