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
    void helper (TreeNode* root, long long sum, int& count) {
        if (root==NULL) return;
        if ((long long) (root->val)==sum) count++;
        helper(root->left, sum-(long long) (root->val), count);
        helper(root->right, sum-(long long) (root->val),count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int count = 0;
        helper(root, (long long) (targetSum),count);
        count += (pathSum(root->left, targetSum) + pathSum(root->right,targetSum));
        return count;
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
    vector<int> nodes = {10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1};
    TreeNode* root = insertLevelOrder(nodes, 0, nodes.size());

    int targetSum = 8;
    Solution sol;
    int result = sol.pathSum(root, targetSum);

    // Print the result.
    cout << "Number of paths with sum " << targetSum << ": " << result << endl;

    return 0;
}