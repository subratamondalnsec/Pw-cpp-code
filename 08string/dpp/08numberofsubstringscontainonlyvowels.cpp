#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int count=0,ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            count++;
        }
        else{
            ans+=(count*(count+1)/2);
            count=0;
        }
    }
    ans+=(count*(count+1)/2);
    cout<<ans;
}