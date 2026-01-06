#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=36;
    for(int i=1;i<sqrt(n);i++){
        if(n%i==0) cout<< i<<" ";
    }
    for(int i=sqrt(n);i>=1;i--){
        if(n%i==0) cout<< n/i<<" ";
    }
}