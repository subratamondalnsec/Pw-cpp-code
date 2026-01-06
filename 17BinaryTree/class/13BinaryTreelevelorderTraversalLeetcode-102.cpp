#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*class Solution {//m1
public:
    int level(TreeNode *root){
        if(root==NULL) return 0;
        return (1+max(level(root->left),level(root->right)));
    }
    void NthlevelelementLtoR(TreeNode *root,int level,vector<int>& v){
        if(root==NULL) return;
        if(level==0){ 
        v.push_back(root->val);
        return;
        }// A ar inoder postorder  korlao same hobe
        NthlevelelementLtoR(root->left,level-1,v);
        NthlevelelementLtoR(root->right,level-1,v);
    }
    void levelorderLtoR(TreeNode *root,vector<vector<int>>& ans){
        int n=level(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            NthlevelelementLtoR(root,i-1,v);
            ans.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode *root){
        vector<vector<int>> ans;
        levelorderLtoR(root,ans);
        return ans;
    }
};*/
class Solution { //m2
public:
    int levels(TreeNode *root){
        if(root==NULL) return 0;
        return (1+max(levels(root->left),levels(root->right)));
    }
    void levelorderLtoR(TreeNode *root,vector<vector<int>>& ans,int level){
        if(root==NULL) return;
        ans[level].push_back(root->val);
        levelorderLtoR(root->left,ans,level+1);
        levelorderLtoR(root->right,ans,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode *root){
        int n=levels(root);
        vector<vector<int>> ans;
        for(int i=1;i<=n;i++){
            vector<int> v;
            ans.push_back(v);
        }
        levelorderLtoR(root,ans,0);
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
    vector<vector<int>> result = sol.levelOrder(root);

    // Print the result.
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}