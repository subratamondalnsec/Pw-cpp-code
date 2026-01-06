#include<bits/stdc++.h>
using namespace std;
int gcd_Euclid(int a,int b){
    if(b==0) return a;
    return gcd_Euclid(b,a%b);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd_Euclid(a,b);
}