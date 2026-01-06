#include<bits/stdc++.h>
using namespace std;
 int fact(int n){
  int f=1;
    for(int i=1;i<=n;i++){
      f*=i;
    }
    return f; 
    }

int combination(int i,int j){
  
  int ncr = fact(i)/(fact(j)*fact(i-j));
    return ncr;
}
int main(){
    int n;
    cout<<"enter the n :";
    cin>>n;
 for(int i=0;i<=n;i++){
     for(int k =1;k<=n-i;k++) cout<<" ";
    for(int j=0;j<=i;j++){
      cout<<combination(i,j)<<" ";
    }
    cout<<endl;
 }
}