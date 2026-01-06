#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {//method 1 using stack 
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(!st.empty() and s[st.top()]=='(') st.pop();
                else st.push(i);
            }
        }
        while(!st.empty()){
            s.erase(st.top(),1);
            st.pop();
        }
        return s;
    }
};

class Solution {//method 2 using stack and set
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<int> st;
        unordered_set<int>remove_id;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(st.empty()) remove_id.insert(i);
                else st.pop();
            }
        }
        while(!st.empty()){
            remove_id.insert(st.top());
            st.pop();
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(remove_id.find(i)==remove_id.end()){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

class Solution {//method 3 
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        string ans="";
        string rans="";
        //iterate left to right ->elminate extra close backet
        int open=0;
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z') ans.push_back(s[i]);
            else if(s[i]=='('){
                open++;
                ans.push_back(s[i]);
            } 
            else if(s[i]==')' && open>0){
                open--;
                ans.push_back(s[i]);
            } 
        }
        //iterate right to left ->elminate extra open backet
        int close =0;
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]>='a' && ans[i]<='z') rans.push_back(ans[i]);
            else if(ans[i]==')'){
                close++;
                rans.push_back(ans[i]);
            } 
            else if(ans[i]=='(' && close>0){
                close--;
                rans.push_back(ans[i]);
            } 
        }
        reverse(begin(rans),end(rans));
        return rans;
    }
};
int main() {
    string s="lee(t(c)o)de)";
    Solution solution;
    cout << "Output: " << solution.minRemoveToMakeValid(s) << endl;
    return 0;
}