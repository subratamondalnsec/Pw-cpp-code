#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,p;
    cin>>s>>p;
    vector<int>cnt_s(26,0) ,cnt_p(26,0),ans;
    int n=s.size();
    int m=p.size();
    if(m>n) cout<<"NO, answer exists"<<endl;
    else{
    for(int i=0;i<m;i++)cnt_p[p[i]-'a']++;

    int i=0;
    for(;i<m;i++){
        cnt_s[s[i]-'a']++;
    }
    bool f=true;
    for(int j=0;j<26;j++ ){
        if(cnt_p[j]!=cnt_s[j]){
            f=false;
            break;
        }
    }
    if(f) ans.push_back(0);
    while(i<n){
        cnt_s[s[i-m]- 'a']--;
        cnt_s[s[i]-'a']++;

        f=true;
        for(int j=0;j<26;j++ ){
        if(cnt_p[j]!=cnt_s[j]){
            f=false;
            break;
        }
    }
    if(f) ans.push_back(i-m+1);
    i++;
    }
    cout<<"the index from this anagram begin are : "<<endl;
    for(auto x:ans) cout<<x<<" ";
    }
}