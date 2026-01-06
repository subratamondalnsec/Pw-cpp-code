#include <bits/stdc++.h>
using namespace std;

int main() {
    string s ;
    getline(cin, s);
    int n=s.length();
    bool flag= true;
    for (int i = 0,j=n-1; i <=n/2;i++,j--) {
        if (s[i] != s[j]){ 
            flag=false;
            break;
        }
        else continue;
    }
    if(flag==true) cout<<"it is a palindrome";
    else cout<<"it is not a palindrome";
    return 0;
}