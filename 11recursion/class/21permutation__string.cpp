#include <bits/stdc++.h>
using namespace std;
void permutation(string ans,string orignal){
    if(orignal==""){
        cout<<ans<<endl;
        return ;
    }
    for(int i=0;i<orignal.size();i++){
        char ch=orignal[i];
        string left=orignal.substr(0,i);
        string right=orignal.substr(i+1);
        permutation(ans+ch,left+right);
    }
}
int main(){
    string str ="abc";
    permutation("",str);
}