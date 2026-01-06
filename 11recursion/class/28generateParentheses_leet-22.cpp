#include <bits/stdc++.h>
using namespace std;
void generateParenthese(string s,int openbacket,int closebacket,int n){
if(closebacket==n) {
    cout<<s<<endl;
    return;
}
if(openbacket<n) generateParenthese(s+'(',openbacket+1,closebacket,n);
if(closebacket < openbacket) generateParenthese(s+')',openbacket,closebacket+1,n);
}
int main(){
    int n=3;
    generateParenthese("",0,0,n);
}
/* leet -22*/
/*class solution{
    public:
    void generate( vector<string>& ans,string s,int openbacket,int closebacket,int n){
if(closebacket==n) {
    ans.push_back(s);
    return;
}
if(openbacket<n) generate(ans,s+'(',openbacket+1,closebacket,n);
if(closebacket < openbacket) generate(ans,s+')',openbacket,closebacket+1,n);
}
    vector<string>generate(int n){
        vector<string> ans;
        generate(ans,"",0,0,n);
        return ans;
    }
};*/