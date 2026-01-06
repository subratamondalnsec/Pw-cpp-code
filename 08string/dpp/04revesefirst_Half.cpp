#include <bits/stdc++.h>
using namespace std;

int main() {
    string s ;
    getline(cin, s);
    int n=s.length();
    reverse(s.begin()+n/2,s.end());
    cout<<s<<endl;
}