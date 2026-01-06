#include<bits/stdc++.h>
using namespace std;
int main(){
    int i,n ;
    bool flag=true;
    cout<<"enter a number : ";
    cin>>n;
    for(i=2;i<=n-1;i++){
    if(n%i==0){
        flag=false;
    break;
   }
    }
    if(n==1)cout<<"1 is neither prime nor composite";
    else if(flag==true)cout<<n<<" : is prime";
    else cout<<n<<" : is composite";
}