#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    
    void help(int i,string temp,string s){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        
        if(s[i]>='0' && s[i]<= '9'){
            temp+= s[i];
            help(i+1, temp, s);
        }
        else{
            temp+= toupper(s[i]);
            help(i+1,temp,s);
            temp.pop_back();
            temp+= tolower(s[i]);
            help(i+1,temp,s);
        }
    } 
    vector<string> letterCasePermutation(string s) {
        string temp="";
        help(0,temp,s);
        return ans;
    }
};

int main() {
    // Input string
    string s = "a1";

    // Create an instance of the Solution class
    Solution solution;

    // Call the function
    vector<string> result = solution.letterCasePermutation(s);

    // Print the result
    cout << "All possible permutations are:" << endl;
    for (const auto& str : result) {
        cout << str << endl;
    }

    return 0;
}