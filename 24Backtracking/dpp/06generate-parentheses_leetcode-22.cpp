/* problem link : https://leetcode.com/problems/generate-parentheses/
By subrata mondal */

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> result;

    bool isValid(string str) {
        int count = 0;
        for(char ch:str) {
            if(ch == '(') count++;
            else count--;
            if(count < 0) return false;
        }
        return count==0;
    }

    void solve(string& curr, int n) {
        if(curr.length() == 2*n) {
            if(isValid(curr)) {
                result.push_back(curr);
            }
            return;
        }

        curr.push_back('(');
        solve(curr, n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(curr, n);

        return result;
    }
};

class Solution {
public:
    vector<string> result;

    void solve(int n, string& curr, int open, int close) {
        if(curr.length() == 2*n) {
            result.push_back(curr);
            return;
        }
        
        if(open < n) {
            curr.push_back('(');
            solve(n, curr, open+1, close);
            curr.pop_back();
        }
        if(close < open) {
            curr.push_back(')');
            solve(n, curr, open, close+1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(n, curr, 0, 0);

        return result;
    }
};

class Solution {
public:
     void generate( vector<string>& ans,string s,int openbacket,int closebacket,int n){
        if(closebacket==n) {
            ans.push_back(s);
            return;
        }
        if(openbacket<n) generate(ans,s+'(',openbacket+1,closebacket,n);
        if(closebacket < openbacket) generate(ans,s+')',openbacket,closebacket+1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans,"",0,0,n);
        return ans;
    }
};


int main() {
    Solution sol; // Create an object of the Solution class
    int n;

    // Input the number of pairs of parentheses
    cout << "Enter the number of pairs of parentheses (n): ";
    cin >> n;

    // Call the generateParenthesis function and store the result
    vector<string> result = sol.generateParenthesis(n);

    // Output the result
    cout << "Generated Parentheses Combinations:" << endl;
    for (const string& str : result) {
        cout << str << endl;
    }

    return 0;
}