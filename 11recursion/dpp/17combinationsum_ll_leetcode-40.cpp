#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void combination2(vector<vector<int>>& ans, vector<int>& v,vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i != idx && candidates[i] == candidates[i - 1]) continue;
            if (target >= candidates[i]) {
                v.push_back(candidates[i]);
                combination2(ans, v, candidates, target - candidates[i],i + 1);
                v.pop_back();
            }
        }
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
