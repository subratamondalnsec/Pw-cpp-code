#include <bits/stdc++.h>
using namespace std;
void storesubset(string ans,string orignal,vector<string> &v){
    if(orignal==""){//sc->bakar
      v.push_back(ans); // cout<<ans<<endl;
        return ;
    }
    char ch=orignal[0];
     storesubset(ans,orignal.substr(1),v);
     storesubset(ans+ch,orignal.substr(1),v);//substr->first element delete
}
int main(){
    string str ="abc";
    vector<string> v;
    storesubset("",str,v);
    for(string ele : v)
    cout<<ele<<endl;
}
