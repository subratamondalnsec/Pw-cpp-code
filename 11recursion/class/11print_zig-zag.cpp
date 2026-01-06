#include <bits/stdc++.h>
using namespace std;
void pip(int n){
    if(n==0) return;
    cout<<n;
    pip(n-1);
    cout<<n;
    pip(n-1);
    cout<<n;
}
int main(){
    for(int i=0;i<=4;i++){
        pip(i);
        cout<<endl; 
    }
}