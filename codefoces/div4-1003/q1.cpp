#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,ans="";
        cin>>s;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i==n-2 &&  s[n-2]=='u' && s[n-1]=='s'){
                ans+='i';
                break;
            } 
            else ans+=s[i];
        }
        cout<<ans<<endl;
    }
}