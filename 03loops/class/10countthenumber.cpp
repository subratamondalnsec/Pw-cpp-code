#include<bits/stdc++.h>
using namespace std;
int main(){
    int i=0,n,count=0,a;
    cout<<"enter a digit : ";
    cin>>n;
    a=n;
while(n>0){
    n/=10;
    count++;
}
if(a==0)cout<<1;
else cout<< count;

}
