#include <bits/stdc++.h>
using namespace std;
void honai(int n,char a,char b,char c){
    if(n==0) return;
    honai(n-1,a,c,b);
    cout<<a<<"->"<<c<<endl;
    honai(n-1,b,a,c);
}
int main(){
    int n=3;
    honai(n,'A','B','C');
}