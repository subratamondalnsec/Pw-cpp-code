#include <bits/stdc++.h>
using namespace std;

int main() {
    string s="12345" ;
    int n =s.length();
    int ans=0;
    for(int i=0;i<n;i++){
        ans*=10;
        ans+=(s[i]-'0');
    }
    cout<<ans;
}