#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "001234567";
    int x=stoi(s);//->(-2^31 to 2^31 -1)
     cout<<x<<endl;
    string t = "1234567891230";
    long long y=stoll(t);//->(-2^63 to 2^63 -1)
     cout<<y<<endl;
}