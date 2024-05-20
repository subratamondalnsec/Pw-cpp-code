#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    //precompute function
    // map<char,int> mpp;
    int hash[1000]={0};
    for(int i=0;i<str.size();i++){
        // mpp[str[i]]++;
        hash[str[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c]<<endl;
    }
}