#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int priority(char ch){
        if(ch=='+' || ch=='-') return 1;
        else return 2;
    }
    string solve(string a,string b,char ch){
        int val1=stoi(a);
        int val2= stoi(b);
        int ans;
        if(ch=='+') ans= val1+val2;
        else if(ch=='-') ans= val1-val2;
        else if(ch=='*') ans =val1*val2;
        else if(ch=='/') ans= val1/val2;
        string q=to_string(ans);
        return q;
    }
    bool isDigit(char ch){
        if(ch>=48 && ch<=57) return true;
        else return false;
    }
    int calculate(string s) {
        string t="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ') t.push_back(s[i]);
        }
        s=t;
        stack<string> val;
        stack<char> op;
        for(int i=0;i<s.length();i++){
            //check if s[i] is a digit
            if(isDigit(s[i])){//digit
                if(i==0 || !isDigit(s[i-1])) val.push(to_string(s[i]-'0'));
                else{
                    string q=val.top();
                    val.pop();
                    q.push_back(s[i]);
                    val.push(q);
                }
            }
            else{
                if(op.size()==0||priority(s[i])>priority(op.top())) op.push(s[i]);
                else {
                    while(op.size()>0 && priority(s[i])<=priority(op.top())){
                        //i have to do val1 op val2
                        char ch = op.top();
                        op.pop();
                        string val2=val.top();
                        val.pop();
                        string val1=val.top();
                        val.pop();
                        string ans=solve(val1,val2,ch);
                        val.push(ans);
                    }
                    op.push(s[i]);
                }
            }
        }
        //the operator stack can have values.
        //so make it empty
        while(op.size()>0 ){
                //i have to do val1 op val2
                char ch = op.top();
                op.pop();
                string val2=val.top();
                val.pop();
                string val1=val.top();
                val.pop();
                string ans=solve(val1,val2,ch);
                val.push(ans);
            }
        return stoi(val.top());
    }
};

int main() {
    Solution sol;
    string expression = "10+5*12-24/4";
    int result = sol.calculate(expression);
    cout << "Result of the expression '" << expression << "' is: " << result << endl;
    return 0;
}