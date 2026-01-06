#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper (TreeNode* root, vector<int> v, vector<vector<int>>& ans, int sum) {
        if (root==NULL) return;
        if(root->left==NULL && root->right==NULL) { // IMP
            if (root->val==sum) {
                v.push_back(root->val);
                ans.push_back(v);
            }
            return;
        }
        v.push_back(root->val);
        helper(root->left,v,ans, sum-(root->val));
        helper(root->right,v,ans, sum-(root->val));
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root,v,ans, targetSum);
        return ans;
    }
};

// Helper function to insert nodes in the binary tree for demonstration.
TreeNode* insertLevelOrder(vector<int> arr, int i, int n) {
    TreeNode* root = nullptr;
    if (i < n) {
        root = new TreeNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

int main() {
    // Example usage:
    vector<int> nodes = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
    TreeNode* root = insertLevelOrder(nodes, 0, nodes.size());

    int targetSum = 22;
    Solution sol;
    vector<vector<int>> result = sol.pathSum(root, targetSum);

    // Print the result.
    for (const auto& path : result) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}