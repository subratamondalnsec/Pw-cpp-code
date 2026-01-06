#include <bits/stdc++.h>
using namespace std;
void removechar(string ans,string orignal){
    if(orignal.length()==0){//sc->bakar
        cout<<ans;
        return ;
    }
    char ch=orignal[0];
    if(ch=='a') removechar(ans,orignal.substr(1));
    else removechar(ans+ch,orignal.substr(1));//substr->first element delete
}
void removecharm2(string ans,string orignal,int idx){
    if(idx==orignal.length()){
        cout<<ans;
        return ;
    }
    char ch=orignal[idx];
    if(ch=='a') removecharm2(ans,orignal,idx+1);
    else removecharm2(ans+ch,orignal,idx+1);
}
int main(){
    string str ="subrata mondal";
    removechar("",str);
    cout<<endl;
    removecharm2("",str,0);
}
