#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0) return false;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(st.size()==0) return false;
                else{
                    char ch;
                    if(st.top()=='(') ch=')';
                    else if(st.top()=='{') ch='}';
                    else if(st.top()=='[') ch=']';
                    
                    if(ch==s[i]) st.pop();
                    else return false;
                }
            }
        }
        if(st.size()==0) return true;
        return false;
    }
};
int main() {
    Solution solution;
    string s;
    
    cout << "Enter a string with parentheses, braces, and/or brackets: ";
    cin >> s;
    
    bool result = solution.isValid(s);
    
    if(result) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is not valid." << endl;
    }
    
    return 0;
}