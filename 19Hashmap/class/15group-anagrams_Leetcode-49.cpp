#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for (string str : arr) {
            string lexo = str;
            sort(lexo.begin(), lexo.end());
            if (m.find(lexo) == m.end()) {
                vector<string> v;
                v.push_back(str);
                m[lexo] = v;
            } else {
                m[lexo].push_back(str);
            }
        }
        for (auto s : m) {
            ans.push_back(s.second);
        }
        return ans;
    }
};

int main() {
    // Create an instance of Solution
    Solution sol;

    // Sample input
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    // Call the groupAnagrams function
    vector<vector<string>> result = sol.groupAnagrams(input);

    // Output the result
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
