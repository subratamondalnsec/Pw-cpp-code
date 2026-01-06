#include<iostream>
using namespace std;
int main(){
    int i,n;
 int p=1;
      cout<<"enter the n : ";
    cin>>n;
    for(i=1;i<n+1;i++){
        p*=i;
        cout<<i<<" its factorial is :"<<p<<endl;
    }
    
}