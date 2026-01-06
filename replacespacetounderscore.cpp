#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="Min Cost to Connect All Points Leetcode-1514";
    string ans="";
    for(int i=0;i<s.length()-1;i++){
        if(s[i] == ' ' ) ans+="_";
        else  ans+=s[i];
    }
    ans+=s[s.length()-1];
    cout<<ans;
}