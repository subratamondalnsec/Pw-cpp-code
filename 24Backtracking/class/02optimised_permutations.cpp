/* By subrata mondal */
#include <bits/stdc++.h>
using namespace std;
void permutations(string &str,int i){
    if(i==str.size()-1){
        cout<<str<<endl;
        return ;
    }
    unordered_set<char>s;
    for(int idx=i;idx<str.size();idx++){
        if(s.count(str[idx])) continue;//avoid repeting element

        s.insert(str[idx]);
        swap(str[idx],str[i]); 
        permutations(str ,i+1);
        swap(str[idx],str[i]); //backtracking 
    }
}
int main(){
    string s="aba";
    permutations(s,0);
}