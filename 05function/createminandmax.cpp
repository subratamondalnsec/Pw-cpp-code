#include<bits/stdc++.h>
using namespace std;
int mini(int x,int y){
    if(x>y) return y;
    else return x;
}
int maxi(int x,int y){
    if(x>y) return x;
    else return y;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<"its minimum number:"<<mini(a,b)<<endl; 
     cout<<"its maximum number:"<<maxi(a,b); 
} 