/* problem link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
By subrata mondal */

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string>ans;
    vector<string>mp;
    void f(int idx,string& s,string temp){

        if(idx>=s.length()){
            ans.push_back(temp);
            return;
        }
        int ch= s[idx]-'0';
        string str=mp[ch];
        for(int i=0;i<str.length();i++){
            temp.push_back(str[i]);
            f(idx+1,s,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        ans.clear();
        mp.resize(10,"");
        int j=0;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";

        f(0,digits,"");
        return ans;
    }
};

int main() {
    Solution solution;
    string digits = "23";  // Example input
    vector<string> result = solution.letterCombinations(digits);

    cout << "Letter Combinations for " << digits << " are: " << endl;
    for (const string& combination : result) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}