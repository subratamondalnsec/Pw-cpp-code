#include <bits/stdc++.h>
using namespace std;
void storesubset2(string ans,string orignal,vector<string> &v,bool flag){
    if(orignal==""){//sc->bakar
      v.push_back(ans); // cout<<ans<<endl;
        return ;
    }
    char ch=orignal[0];
    if(orignal.length()==1){
      if(flag==true) storesubset2(ans+ch,orignal.substr(1),v,true);
      storesubset2(ans,orignal.substr(1),v,true);
      return;
    }
    char dh=orignal[1];
    if(ch==dh){
      if(flag==true) storesubset2(ans+ch,orignal.substr(1),v,true);
      storesubset2(ans,orignal.substr(1),v,false);
      return;
    }
    else{
      if(flag==true) storesubset2(ans+ch,orignal.substr(1),v,true);
      storesubset2(ans,orignal.substr(1),v,true);
      return;
    }
}
int main(){
    string str ="aaaba";
    sort(str.begin(),str.end());
    vector<string> v;
    storesubset2("",str,v,true);
    for(string ele : v)
    cout<<ele<<endl;
}
