/* problem link : https://leetcode.com/problems/combination-sum-ii/
By subrata mondal */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void combination2(vector<vector<int>>& ans, vector<int>& v,vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        if(idx==candidates.size()) return ;
        if (target >= candidates[idx]) {
            v.push_back(candidates[idx]);
            combination2(ans, v, candidates, target - candidates[idx],idx + 1);//pick
            v.pop_back();
        }

        int j=idx+1;
        while(j < candidates.size() && candidates[j] == candidates[j - 1]) j++;
        combination2(ans, v, candidates, target,j);//non pick
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combination2(ans, v, candidates, target, 0);
        return ans;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    // Calling the function
    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    // Printing the result
    cout << "Combinations that sum to " << target << ":" << endl;
    for (const auto& combination : result) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
