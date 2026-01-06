#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(int i=0; i < s.length(); i++)  m[s[i]]++;
        
        priority_queue<pair<int,char>> pq;
        for(auto ele: m) pq.push({ele.second, ele.first});
        
        pair<int,char> prev = {0, '*'};
        string ans = "";
        
        while(pq.size() > 0) {
            auto curr = pq.top();
            pq.pop();
            
            if(prev.first > 0) pq.push(prev);
            
            ans += curr.second;
            curr.first--;
            prev = curr;
        }
        
        if(ans.length() != s.length()) return "";
        else return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1: Input string with possible reorganization
    string input1 = "aab";
    string result1 = sol.reorganizeString(input1);
    if (result1 != "") {
        cout << "Reorganized string: " << result1 << endl;
    } else {
        cout << "Reorganization not possible." << endl;
    }

    // Example 2: Input string where reorganization is not possible
    string input2 = "aaab";
    string result2 = sol.reorganizeString(input2);
    if (result2 != "") {
        cout << "Reorganized string: " << result2 << endl;
    } else {
        cout << "Reorganization not possible." << endl;
    }

    return 0;
}
