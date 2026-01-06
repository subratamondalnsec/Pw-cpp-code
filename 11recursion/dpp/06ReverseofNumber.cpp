#include<bits/stdc++.h>
using namespace std;
void reverseofdigit(int n,int &ans){
    if(n==0) return;
    int dight=(n%10);
    ans=ans*10+dight;
    reverseofdigit(n/10,ans);
}
int main(){
    int n;
    cin>>n;
    int digit=0;
    reverseofdigit(n,digit);
    cout<< digit;
}