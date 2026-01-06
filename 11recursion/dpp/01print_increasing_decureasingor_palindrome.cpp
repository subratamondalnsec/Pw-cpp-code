#include<bits/stdc++.h>
using namespace std;
// void increasing(int n){
//     if(n==0) return;
//     increasing(n-1);
//     cout<<n<<" ";
// }
// void decreasing(int n){
//     if(n==0) return;
//     cout<<n<<" ";
//     decreasing(n-1);
// }
// void palindrome(int n){
//     increasing(n);
//     decreasing(n-1);
// }

void palindrome(int n,int i){
    if(i>n) return;
    cout<<i<<" ";
    palindrome(n,i+1);
    if(i>1) cout<<i-1<<" ";
}


int main(){
    int n;
    cout<<" The number of palindrome :";
    cin>>n;
    palindrome(n,1);
}