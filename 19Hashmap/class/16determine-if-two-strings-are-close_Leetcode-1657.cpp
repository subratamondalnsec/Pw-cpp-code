#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        
        unordered_map<char, int> m1, m2;
        for(int i = 0; i < s1.length(); i++) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        
        for(auto x : m1) {
            char ch = x.first;
            if(m2.find(ch) == m2.end()) return false;
        }
        
        unordered_map<int, int> h1, h2;
        for(auto x : m1) {
            int freq = x.second;
            h1[freq]++;
        }
        for(auto x : m2) {
            int freq = x.second;
            h2[freq]++;
        }
        
        for(auto x : h1) {
            int key = x.first;
            if(h2.find(key) == h2.end()) return false;
            if(h2[key] != h1[key]) return false;
        }
        return true;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string s1 = "abc";
    string s2 = "bca";
    cout << (solution.closeStrings(s1, s2) ? "True" : "False") << endl;
    
    // Test case 2
    s1 = "aabbcc";
    s2 = "bbccaa";
    cout << (solution.closeStrings(s1, s2) ? "True" : "False") << endl;
    
    // Test case 3
    s1 = "abc";
    s2 = "def";
    cout << (solution.closeStrings(s1, s2) ? "True" : "False") << endl;
    
    return 0;
}
