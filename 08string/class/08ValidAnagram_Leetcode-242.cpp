#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "anagram";
   string t = "nagaram";
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s==t) cout<<true;
    else cout<< false;
}