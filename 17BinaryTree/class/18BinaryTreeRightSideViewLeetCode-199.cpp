#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void helper(TreeNode *root, int level, vector<int> &ans){
        if(root==NULL) return ;
        if(ans.size()==level) ans.push_back(root->val);
        helper(root->right, level+1, ans);
        helper(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root, 0, ans);
        return ans;
    }
};
class Solution {
public:
    int level(TreeNode*root){
        if(root==NULL) return 0;
        return (1+max(level(root->left),level(root->right)));
    }
    void NthlevelelementLtoR(TreeNode *root,int curr,int level,vector<int>& ans){
        if(root==NULL) return;
        if(curr==level){ 
            ans[curr]=root->val;
        return;
        }// A ar inoder postorder  korlao same hobe
        NthlevelelementLtoR(root->left,curr+1,level,ans);
        NthlevelelementLtoR(root->right,curr+1,level,ans);
    }
    void levelorderLtoR(TreeNode*root,vector<int>& ans){
        int n=ans.size();
        for(int i=0;i<n;i++){
            NthlevelelementLtoR(root,0,i,ans);
        }
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(level(root),0);
        levelorderLtoR(root,ans);
        return ans;
    }
};

class Solution {
public:
    int level(TreeNode*root){
        if(root==NULL) return 0;
        return (1+max(level(root->left),level(root->right)));
    }
    void preorder(TreeNode *root,int level,vector<int>& ans){
        if(root==NULL) return; 
        ans[level]=root->val;
        preorder(root->left,level+1,ans);
        preorder(root->right,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(level(root),0);
        preorder(root,0,ans);
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
    vector<int> nodes = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = insertLevelOrder(nodes, 0, nodes.size());

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    // Print the result.
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}