#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string s,string t){
    if(s.size()!=t.size()) return false;
    int n=s.size();
    vector<int>cne(26,0);
    for(int i=0;i<n;i++){
        cne[s[i]-'a']++;
        cne[t[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(cne[i]!=0) return false;
    }
    return true;
}

int main() {
    string s;
    string t;
    cin>>s>>t;
    isAnagram?cout<<"yes,it is a anagram" : cout<<"No,it is not a anagram";
}