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
    void helper(TreeNode* root, string s, vector<string>& ans) {
        if (root==NULL) return;
        string a = to_string(root->val);
        if (root->left==NULL && root->right==NULL) { // IMP
        s += a;
        ans.push_back(s);
        return;
        }
        helper(root->left, s+a+"->", ans);
        helper(root->right, s+a+"->", ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};

int main() {
    // Creating a sample binary tree
    //        1
    //       / \
    //      2   3
    //       \
    //        5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<string> paths = solution.binaryTreePaths(root);

    cout << "Binary tree paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    // Clean up memory
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

