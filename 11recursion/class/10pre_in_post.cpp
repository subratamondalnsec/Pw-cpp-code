#include <bits/stdc++.h>
using namespace std;
void pip(int n){
    if(n==0) return;
    cout<<"pre"<<n<<endl;
    pip(n-1);
    cout<<"in"<<n<<endl;
    pip(n-1);
    cout<<"post"<<n<<endl;
}
int main(){
    pip(3);
}