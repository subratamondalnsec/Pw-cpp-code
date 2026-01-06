/* problem link : https://leetcode.com/problems/combination-sum/
By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combination(vector<vector<int>>& ans, vector<int>& v,vector<int>& candidates, int target, int idx) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        if(idx==candidates.size()) return ;
        if (target >= candidates[idx]) {
            v.push_back(candidates[idx]);
            combination(ans, v, candidates, target - candidates[idx],idx);//pick
            v.pop_back();
        }

        int j=idx+1;
        while(j < candidates.size() && candidates[j] == candidates[j - 1]) j++;
        combination(ans, v, candidates, target,j);//non pick
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combination(ans, v, candidates, target, 0);
        return ans;
    }
};


int main() {
    Solution solution;
    int n, target;
    
    cout << "Enter the number of candidates: ";
    cin >> n;
    vector<int> candidates(n);
    cout << "Enter the candidates: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }
    cout << "Enter the target sum: ";
    cin >> target;
    
    vector<vector<int>> result = solution.combinationSum(candidates, target);
    
    cout << "Combination sums that add up to " << target << " are:" << endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}