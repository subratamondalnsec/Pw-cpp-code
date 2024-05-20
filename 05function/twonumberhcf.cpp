#include<bits/stdc++.h>
using namespace std;
   int hcf(int a,int b){
    int gcd=1;
    for(int i=min(a,b);i>=1;i--){
        if(a%i==0  && b%i==0){
         gcd=i;
         break;
        }
    }
    return gcd;
   }
int main(){
    int a,b;
    cout<<"enter the 1st number:";
    cin>>a;
     cout<<"enter the 2nd number:";
    cin>>b;
    cout<<hcf(a,b);
}