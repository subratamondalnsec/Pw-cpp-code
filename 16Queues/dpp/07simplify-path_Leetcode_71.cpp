#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string s) {
        stack<string>st;
        for(int i=0;i<s.length();i++){
           if(s[i]=='/') continue;
            string temp="";
            while(i<s.size() && s[i]!='/'){
                temp+=s[i];
                i++;
            }
            //cout<<temp;
            if(temp==".") continue;
            else if(temp==".."){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(temp); 
            } 
        }
        string res="";
        while(!st.empty()){
            res="/"+st.top()+res;
            st.pop();
        }
        if(res.size()==0) return "/";
        return res;
    }
};

int main() {
    Solution sol;  // Create an instance of the Solution class
    
    string path = "/home//foo/";  // Example input
    string result = sol.simplifyPath(path);  // Call the simplifyPath method
    
    cout << "Simplified Path: " << result << endl;  // Output the result

    return 0;
}